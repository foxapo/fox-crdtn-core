typedef CRDTN_Core_ItemUtils ItemUtils;

class CRDTN_Core_ItemUtils
{
    static EntityAI SpawnItem(CRDTN_Item item, string position, string orientation)
    {
        EntityAI entity = EntityAI.Cast(GetGame().CreateObject(item.ClassName, position.ToVector(), false, true));
        if (!entity)
        {
            return null;
        }

        if (!entity.GetInventory())
        {
            return entity;
        }

        if (item.Attachments != null && item.Attachments.Count() > 0)
        {
            foreach (CRDTN_Item attachment : item.Attachments)
            {
                entity.GetInventory().CreateAttachment(attachment.ClassName);
            }
        }

        return entity;
    }

    static bool IsInventoryEmpty(EntityAI ent)
    {
        array<EntityAI> objects = new array<EntityAI>;
        int count = 0;
        if (ent.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, objects))
        {
            foreach (EntityAI obj : objects)
            {
                if (obj.GetType() == ent.GetType())
                {
                    continue;
                }
                count++;
            }
            return count == 0;
        }
        return true;
    }

    static bool HasArmor(EntityAI ent)
    {
        return GetGame().ConfigIsExisting(string.Format("CfgVehicles %1 DamageSystem GlobalArmor", ent.GetType()));
    }

    
    static int GetItemCount(ItemBase item)
    {
        Magazine mgzn = Magazine.Cast(item);
        int itemAmount = 0;
        if (item.IsMagazine())
        {
            itemAmount = mgzn.GetAmmoCount();
        }
        else
        {
            itemAmount = QuantityConversions.GetItemQuantity(item);
        }
        return itemAmount;
    }

    static string GetDisplayName(string className, string path = CFG_VEHICLESPATH)
    {
        if (!className || className == "")
        {
            return "";
        }

        string cfg_item = "CfgVehicles " + className + " displayName";
        if (!GetGame().ConfigIsExisting(cfg_item))
        {
            cfg_item = "cfgWeapons " + className + " displayName";
            if (!GetGame().ConfigIsExisting(cfg_item))
            {
                return "";
            }
        }

        string displayName = GetGame().ConfigGetTextOut(cfg_item);
        if (!displayName || "")
        {
            displayName = className;
        }

        return displayName;
    }

    /// @brief Finds an item in inventory and returns it, otherwise returns NULL
    static ref array<Object> FindItemArrayInInventory(string type, PlayerBase pl = null, bool notRuined = false)
    {
        ref array<Object> result = new ref array<Object>;
        type.ToLower();

        if (GetGame().IsClient() && pl == null)
        {
            pl = PlayerBase.Cast(GetGame().GetPlayer());
        }

        array<EntityAI> objects = new array<EntityAI>;

        if (!pl)
            return null;

        pl.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, objects);

        for (int i = 0; i < objects.Count(); i++)
        {
            EntityAI obj = objects.Get(i);
            string check_type = obj.GetType();
            check_type.ToLower();

            if (check_type == type)
            {
                if (!notRuined)
                {
                    result.Insert(obj);
                }
                else
                {
                    if (!obj.IsRuined())
                    {
                        result.Insert(obj);
                    }
                }
            }
        }

        return result;
    }

    static ref array<Object> FindItemInEntityInventory(string type, EntityAI entity, bool notRuined = false)
    {
        ref array<Object> result = new ref array<Object>;
        type.ToLower();

        if (!entity || !entity.GetInventory())
            return null;

        array<EntityAI> objects = new array<EntityAI>;

        entity.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, objects);

        for (int i = 0; i < objects.Count(); i++)
        {
            EntityAI obj = objects.Get(i);
            string check_type = obj.GetType();
            check_type.ToLower();

            if (check_type == type)
            {
                if (!notRuined)
                {
                    result.Insert(obj);
                }
                else
                {
                    if (!obj.IsRuined())
                    {
                        result.Insert(obj);
                    }
                }
            }
        }

        return result;
    }

    static bool HasItemInInventory(string item, PlayerBase pl = NULL)
    {
        if (!pl)
        {
            return false;
        }

        ItemBase itm = FindItemInInventory(item, pl);
        if (item)
            return true;

        return false;
    }

    /// @brief Finds an item in inventory and returns it, otherwise returns NULL
    static ItemBase FindItemInInventory(string type, PlayerBase pl = NULL)
    {
        if (GetGame().IsClient())
        {
            pl = PlayerBase.Cast(GetGame().GetPlayer());
        }
        type.ToLower();
        array<EntityAI> m_Objects = new array<EntityAI>;
        int i = 0;
        ItemBase item;
        if (!pl)
            return NULL;

        pl.GetInventory().EnumerateInventory(InventoryTraversalType.PREORDER, m_Objects);

        for (i = 0; i < m_Objects.Count(); i++)
        {
            item = ItemBase.Cast(m_Objects[i]);
            if (item)
            {
                string item_type = item.GetType();
                item_type.ToLower();
                if (item_type == type)
                {
                    return item;
                }
            }
        }

        return null;
    }

    /// @brief Get quantity of item with quantity, otherwise return 1 because this method expects that Item exists at least once
    /// @param item
    /// @return
    static int GetQuantityNumberOfItem(ItemBase item, bool checkRuined = false)
    {
        if (!item) // Quantity is 0 if the item does not exist
        {
            return 0;
        }
        if (checkRuined && item.IsRuined())
        {
            return 0;
        }
        int quantity = 1;
        int quantityType = QuantityConversions.HasItemQuantity(item);
        if (quantityType == QUANTITY_HIDDEN)
        {
            quantity = QuantityConversions.GetItemQuantity(item);
        }
        else
        {
            float q_cur = 0;
            float q_min = 0;
            float q_max = 0;
            QuantityConversions.GetItemQuantity(item, q_cur, q_min, q_max);
            quantity = q_cur;
        }
        return quantity;
    }

    static int GetItemMaxQuantity(string itemClassname)
    {
        TStringArray searching_in = new TStringArray;
        searching_in.Insert(CFG_MAGAZINESPATH + " " + itemClassname + " count");
        searching_in.Insert(CFG_VEHICLESPATH + " " + itemClassname + " varQuantityMax");
        for (int s = 0; s < searching_in.Count(); ++s)
        {
            string path = searching_in.Get(s);

            if (GetGame().ConfigIsExisting(path))
            {
                return g_Game.ConfigGetInt(path);
            }
        }
        return 0;
    }

    static bool HasQuantity(string className)
    {
        return GetItemMaxQuantity(className) > 0;
    }

    
    static int GetTotalQuantityOfItems( array<Object> items, bool hasQuantity)
    {
        int totalQuantity = 0;
        for (int i = 0; i < items.Count(); i++)
        {
            ItemBase item = ItemBase.Cast(items.Get(i));
            if (item == NULL)
            {
                continue;
            }

            if (item.IsRuined())
            {
                continue;
            }
            // Check the quantity of the item
            if (hasQuantity)
            {
                totalQuantity += item.GetQuantity();
            }
            else
            {
                totalQuantity++;
            }
        }
        return totalQuantity;
    }


};