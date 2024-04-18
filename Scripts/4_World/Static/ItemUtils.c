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
};