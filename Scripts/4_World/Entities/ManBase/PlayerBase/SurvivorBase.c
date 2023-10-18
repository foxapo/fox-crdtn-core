modded class SurvivorBase
{
    protected bool m_IsQuestGiver = false;
    protected string m_GiverId = "";
    protected string m_Name = "";
    protected string m_ActionText = "";


    override void EEInit()
    {
        super.EEInit();
        if(GetGame().IsClient())
        {
            GetGame().RPCSingleParam(this, CRDTN_RPC_NPC.SYNC_NPC, null, true);
        }
    }

    override string GetDisplayName()
    {
        return m_Name;
    }

    string GetActionText()
    {
        return m_ActionText;
    }

    void EquipInHands(string classname)
    {
        Man man = Man.Cast(this);
        man.GetHumanInventory().CreateInHands(classname);
    }

    void SyncToClient()
    {
        if(!GetGame().IsServer())
        {
            return;
        }
        GetGame().RPCSingleParam(this, CRDTN_RPC_NPC.SYNC_NPC, new Param2<string, string>(m_Name, m_GiverId), true);
    }

    void EquipCRDTN_Item(CRDTN_Item item)
    {
        Man man = Man.Cast(this);
        EntityAI ent = EntityAI.Cast(man.GetHumanInventory().CreateInHands(item.ClassName));
        if(ent && ent.GetInventory())
        {
            foreach(CRDTN_Item attachment : item.Attachments)
            {
                ent.GetInventory().CreateAttachment(attachment.ClassName);
            }
        }
    }
};