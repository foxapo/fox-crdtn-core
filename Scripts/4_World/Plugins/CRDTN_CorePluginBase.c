class CRDTN_CorePluginBase : CRDTN_PluginBase
{

    protected ref CRDTN_Config m_Config;

    override void InitRPCs()
    {
        GetRPCManager().AddRPC(CFG_CRDTN_Core_Prefix, "RPC_ServerConfigReceived", this, SingleplayerExecutionType.Both);
        GetRPCManager().AddRPC(CFG_CRDTN_Core_Prefix, "RPC_PlaySoundOnClient", this, SingleplayerExecutionType.Both);
    }

    override void InitData()
    {
        m_Config = new CRDTN_Config();
    }
    
    override void ParseData()
    {
        CRDTN_ConfigLoader<ref CRDTN_Config>.Init("$profile:CRDTN\\CRDTN_Core.json", m_Config);
    }

    CRDTN_Config GetConfig()
    {
        return m_Config;
    }

};
