modded class MissionServer
{
    override void OnInit()
    {
        super.OnInit();
        DebugUtils.Log(CFG_CRDTN_Core_Prefix + ": MissionServer::OnInit()");
    }

    /// @brief Called when connected or respawned
    /// @param player 
    /// @param identity 
    /// @return 
    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
    {
        super.InvokeOnConnect(player, identity);
        if(!GetCRDTN_CorePluginServer())
        {
            return;
        }

        // Send the server config to player
        DebugUtils.Log(CFG_CRDTN_Core_Prefix + ": Sending config to player");
        GetCRDTN_CorePluginServer().OnPlayerConnected(identity, player);

        if(!GetCRDTN_CorePluginServer().GetConfig())
        {
            DebugUtils.Log(CFG_CRDTN_Core_Prefix + ": Intro notification disabled");
            return;
        }

        if(GetCRDTN_CorePluginServer().GetConfig().CRDTN_DisableIntroNotification)
        {
            DebugUtils.Log(CFG_CRDTN_Core_Prefix + ": Intro notification disabled");
            return;
        }

        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SendWelcomeNotification, 5000, false, identity);
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SendMessageToPlayer, 5000, false, player);
    }

    /// @brief This method can be also called from different mods. You can override and leave it empty if you want to get rid of the welcome notification
    /// @param identity 
    void SendWelcomeNotification(PlayerIdentity identity)
    {
        DebugUtils.Log(CFG_CRDTN_Core_Prefix + ": CRDTN_Core Sending welcome notification");
        NotificationSystem.SendNotificationToPlayerIdentityExtended(identity, 3,  "Welcome survivor!", "Welcome to " + GetCRDTN_CorePluginServer().GetConfig().CRDTN_ServerName, "set:ccgui_enforce image:MapUserMarker");
    }

    void SendMessageToPlayer(PlayerBase player)
    {
        player.MessageAction(" >> You're playing on a server powered by CRDTN Core << ");
    }
};