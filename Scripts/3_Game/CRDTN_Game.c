modded class DayZGame
{
    private ref CRDTN_EventHandler m_CRDTN_EventHandler;
    
    private static ref CRDTN_Config m_CRDTN_Config = NULL;

    void DayZGame()
    {
        Print(CFG_CRDTN_Core_Prefix + " Game::DayZGame() initializing CRDTN CORE");
        m_CRDTN_EventHandler = new CRDTN_EventHandler();
    }
    
    CRDTN_EventHandler CRDTNGetEventHandler()
    {
        return m_CRDTN_EventHandler;
    }

    override void InitNotifications()
	{
		NotificationSystem.InitInstance();
        m_Notifications = new CRDTN_NotificationUI;
	}

    void SetConfig(ref CRDTN_Config cfg)
    {
        m_CRDTN_Config = cfg;
        if(GetGame().IsClient())
        {
            // Update the notification settings
            m_Notifications.SetNotificationElementPath(m_CRDTN_Config.CRDTN_Notifications);
        }
    }

    ref CRDTN_Config GetConfig()
    {
        return m_CRDTN_Config;
    }
}
