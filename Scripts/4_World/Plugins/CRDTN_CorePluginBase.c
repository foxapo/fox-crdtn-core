class CRDTN_CorePluginBase : CRDTN_PluginBase
{

    protected ref CRDTN_Config m_Config;

    override void InitRPCs()
    {
        GetRPCManager().AddRPC(CFG_CRDTN_Core_Prefix, "RPC_ServerConfigReceived", this, SingleplayerExecutionType.Both);
        GetRPCManager().AddRPC(CFG_CRDTN_Core_Prefix, "RPC_PlaySoundOnClient", this, SingleplayerExecutionType.Both);
        GetRPCManager().AddRPC(CFG_CRDTN_Core_Prefix, "RPC_PlaySoundOnClientObject", this, SingleplayerExecutionType.Both);
    }

    CRDTN_Config GetConfig()
    {
        return m_Config;
    }

};
