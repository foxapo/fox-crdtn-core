modded class MissionServer
{
    override void OnInit()
    {
        super.OnInit();
        DebugUtils.Log(": CRDTN_Core Init Server");
    }

    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
    {
        super.InvokeOnConnect(player, identity);
        if(GetCRDTN_CorePluginServer())
        {
            GetCRDTN_CorePluginServer().OnPlayerConnected(identity, player);
        }
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SendWelcomeNotification, 5000, false, identity);
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SendMessageToPlayer, 5000, false, player);
    }

    /// @brief This method can be also called from different mods. You can override and leave it empty if you want to get rid of the welcome notification
    /// @param identity 
    void SendWelcomeNotification(PlayerIdentity identity)
    {
        NotificationSystem.SendNotificationToPlayerIdentityExtended(identity, 3,  "Welcome " + identity.GetName() + " !", "Welcome to " + GetCRDTN_CorePlugin().GetConfig().CRDTN_ServerName);
    }

    void SendMessageToPlayer(PlayerBase player)
    {
        player.MessageAction(" >> You're playing on a server powered by CRDTN Core << ");
    }
};