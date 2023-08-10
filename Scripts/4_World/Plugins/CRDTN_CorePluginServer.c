class CRDTN_CorePluginServer : CRDTN_CorePluginBase
{
    void CRDTN_CorePluginServer()
    {
        DebugUtils.Log(CFG_CRDTN_Core_Prefix + " Server::CRDTN_CorePluginServer()");
    }

    override void InitRPCs()
    {
        return;
    }

    override void ParseData()
    {
        if(CRDTN_ConfigLoader<CRDTN_Config>.Init("$profile:CRDTN\\CRDTN_Core.json", m_Config))
        {
            DebugUtils.Log("Loaded from file CRDTN_Core.json");
            m_Config.PrintData();
        }
    }

    void OnPlayerConnected(PlayerIdentity identity, PlayerBase player)
    {   
        GetRPCManager().SendRPC(CFG_CRDTN_Core_Prefix, "RPC_ServerConfigReceived", new Param1<CRDTN_Config>(m_Config), false, identity);
    }

    void PlaySoundOnClient(PlayerBase player, string soundSetName)
    {
        GetRPCManager().SendRPC(CFG_CRDTN_Core_Prefix, "RPC_PlaySoundOnClient", new Param1<string>(soundSetName), false, player.GetIdentity());
    }
};

CRDTN_CorePluginServer GetCRDTN_CorePluginServer()
{
    return CRDTN_CorePluginServer.Cast(GetPluginManager().GetPluginByType(CRDTN_CorePluginServer));
}