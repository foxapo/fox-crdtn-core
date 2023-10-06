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
};