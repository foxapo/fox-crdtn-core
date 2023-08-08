modded class DayZGame
{
    private ref CRDTN_EventHandler  m_CRDTN_EventHandler        = new CRDTN_EventHandler;
    private ref CRDTN_Config        m_CRDTN_Config              = new CRDTN_Config;

    void DayZGame()
    {
        Print(CFG_CRDTN_Core_Prefix + " Game::DayZGame() initializing CRDTN CORE");
        m_CRDTN_EventHandler = new CRDTN_EventHandler();
    }
    
    CRDTN_EventHandler CRDTNGetEventHandler()
    {
        return m_CRDTN_EventHandler;
    }

    CRDTN_Config GetConfig()
    {
        return m_CRDTN_Config;
    }

    override void InitNotifications()
	{
		NotificationSystem.InitInstance();
        m_Notifications = new CRDTN_NotificationUI;
	}

    void SetCRDTNCoreConfig(ref CRDTN_Config cfg)
    {
        if(IsClient())
        {
            m_CRDTN_Config = cfg;
            m_CRDTN_Config.PrintData();
            m_Notifications.SetNotificationLayout(m_CRDTN_Config.CRDTN_Notifications);
        }
    }
}
