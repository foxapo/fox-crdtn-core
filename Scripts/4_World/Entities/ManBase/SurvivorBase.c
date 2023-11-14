modded class SurvivorBase
{
    protected string m_NpcName    = "";
    protected string m_ActionText = "";
    protected ref CRDTN_NpcInfo m_NpcInfo = NULL;

    override void EEInit()
    {
        super.EEInit();
        if(GetGame().IsClient())
        {
            GetGame().RPCSingleParam(this, CRDTN_RPC_NPC.SYNC_NPC_INFO, null, true);
        }
    }

    string GetActionText()
    {
        return m_ActionText;
    }

    override string GetDisplayName()
    {
        if(m_NpcName != "")
        {
            return m_NpcName;
        }
        else
        {
            return super.GetDisplayName();
        }
    }

    void SetNpcInfo(ref CRDTN_NpcInfo npcInfo)
    {
        CRDTN_FileLogger.GetInstance("Trading").Log("SetNpcInfo " + npcInfo);
        m_NpcInfo = npcInfo;
        if(npcInfo == null)
        {
            return;
        }

        m_NpcName =  npcInfo.GetParam(CRDTN_NpcInfo.NPC_INFO_NPC_NAME);
        CRDTN_FileLogger.GetInstance("Trading").Log("SetNpcInfo m_NpcName " + m_NpcName);
        SetNpcInfoImpl(npcInfo);

        if(!GetGame().IsServer())
        {
            return;
        }

        GetGame().RPCSingleParam(this, CRDTN_RPC_NPC.SYNC_NPC_INFO, new Param1<ref CRDTN_NpcInfo>(m_NpcInfo), true);
    }

    /// @brief Override this in the mods to add custom actions to the NPC
    /// @param npcInfo 
    void SetNpcInfoImpl(ref CRDTN_NpcInfo npcInfo);
    
    void EquipInHands(string classname)
    {
        GetHumanInventory().CreateInHands(classname);
    }

    void SyncToClient()
    {
        GetGame().RPCSingleParam(this, CRDTN_RPC_NPC.SYNC_NPC_INFO, new Param1<ref CRDTN_NpcInfo>(m_NpcInfo), true);
    }

    override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        super.OnRPC(sender, rpc_type, ctx);
        if (rpc_type == CRDTN_RPC_NPC.SYNC_NPC_INFO)
        {
            if (!GetGame().IsClient())
            {
                GetGame().RPCSingleParam(this, CRDTN_RPC_NPC.SYNC_NPC_INFO, new Param1<ref CRDTN_NpcInfo>(m_NpcInfo), true);
                return;
            }

            Param1<ref CRDTN_NpcInfo> data;
            if (!ctx.Read(data))
            {
                return;
            }

            SetNpcInfo(data.param1);
        }
    }

    void EquipCRDTN_Item(CRDTN_Item item)
    {
        EntityAI ent = GetHumanInventory().CreateInHands(item.ClassName);
        if(ent && ent.GetInventory())
        {
            foreach(CRDTN_Item attachment : item.Attachments)
            {
                ent.GetInventory().CreateAttachment(attachment.ClassName);
            }
        }
    }
};