class CRDTN_CorePluginServer : CRDTN_CorePluginBase
{
    override void ParseData()
    {
        super.ParseData();
        // Load m_Config from a json file 
        if(CRDTN_ConfigLoader<CRDTN_Config>.Init("$profile:CRDTN\\CRDTN_Core.json", m_Config))
        {
            DebugUtils.Log("Loaded from file CRDTN_Core.json");
            m_Config.PrintData();
        }
    }

    void OnPlayerConnected(PlayerIdentity identity, PlayerBase player)
    {   
        GetRPCManager().SendRPC(CFG_CRDTN_Core_Prefix, "RPC_ServerConfigReceived", new Param1<ref CRDTN_Config>(m_Config), true, identity);
    }
};

CRDTN_CorePluginServer GetCRDTN_CorePluginServer()
{
    return CRDTN_CorePluginServer.Cast(GetPluginManager().GetPluginByType(CRDTN_CorePluginServer));
}