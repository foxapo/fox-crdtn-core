class CRDTN_CorePluginBase : CRDTN_PluginBase
{
    protected ref CRDTN_Config m_Config;
    
    override void InitData()
    {
        m_Config = new CRDTN_Config();
    }

    override void InitRPCs()
    {
        GetRPCManager().AddRPC("CRDTN_Core", "RPC_ServerConfigReceived", this, SingleplayerExecutionType.Both);
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