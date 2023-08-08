modded class MissionServer
{
    override void OnInit()
    {
            DebugUtils.Log(": CRDTN_Core Init Server");
            super.OnInit();
    }

    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
    {
        super.InvokeOnConnect(player, identity);
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SendWelcomeNotification, 5000, false, identity);
    }

    /// @brief This method can be also called from different mods. You can override and leave it empty if you want to get rid of the welcome notification
    /// @param identity 
    void SendWelcomeNotification(PlayerIdentity identity)
    {
        NotificationSystem.SendNotificationToPlayerIdentityExtended(identity, 3,  "Welcome " + identity.GetName() + " !", "Welcome to " + GetCRDTN_CorePlugin().GetConfig().CRDTN_ServerName);
        player.MessageAction(" >> You're playing on a server powered by CRDTN Core << ");
    }
};