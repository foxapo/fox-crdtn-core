class CRDTN_CorePluginServer : CRDTN_CorePluginBase
{
    void CRDTN_CorePluginServer()
    {
        DebugUtils.Log(CFG_CRDTN_Core_Prefix + " Server::CRDTN_CorePluginServer()");
    }

    override void InitData()
    {
        m_Config = GetDayZGame().GetConfig();
        AdminUtils.AdminIds = m_Config.CRDTN_AdminList;
        DebugUtils.Log(CFG_CRDTN_Core_Prefix + " Set config from DayZGame");
    }

    void OnPlayerConnected(PlayerIdentity identity, PlayerBase player)
    {
        GetRPCManager().SendRPC(CFG_CRDTN_Core_Prefix, "RPC_ServerConfigReceived", new Param1<ref CRDTN_Config>(m_Config), false, identity);
    }

    void PlaySoundOnClient(PlayerBase player, string soundSetName)
    {
        GetRPCManager().SendRPC(CFG_CRDTN_Core_Prefix, "RPC_PlaySoundOnClient", new Param1<string>(soundSetName), false, player.GetIdentity());
    }

    void InitMission(string serverName)
    {
        DebugUtils.LogGame(serverName, " Server::CRDTN_CorePluginServer():InitMission()");
    }
};

CRDTN_CorePluginServer GetCRDTN_CorePluginServer()
{
    return CRDTN_CorePluginServer.Cast(GetPluginManager().GetPluginByType(CRDTN_CorePluginServer));
}