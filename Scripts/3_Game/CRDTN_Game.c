modded class DayZGame
{
    private ref CRDTN_EventHandler  m_CRDTN_EventHandler        = new CRDTN_EventHandler;
    private ref CRDTN_Config        m_CRDTN_Config              = new CRDTN_Config;

    void DayZGame()
    {
        Print(CFG_CRDTN_Core_Prefix + " Game::DayZGame() CRDTN CORE");
    
        #ifdef CRDTN_Sounds
        Print(CFG_CRDTN_Core_Prefix + " Game::DayZGame() CRDTN_SOUNDS enabled");
        #endif

        #ifdef CRDTN_Gui
        Print(CFG_CRDTN_Core_Prefix + " Game::DayZGame() CRDTN_GUI enabled");
        #endif

        #ifdef CRDTN_Quests
        Print(CFG_CRDTN_Core_Prefix + " Game::DayZGame() CRDTN_QUESTS enabled");
        #endif

        #ifdef CRDTN_Factions
        Print(CFG_CRDTN_Core_Prefix + " Game::DayZGame() CRDTN_FACTIONS enabled");
        #endif

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
        m_CRDTN_Config = cfg;
        m_CRDTN_Config.PrintData();
        if(m_CRDTN_Config.CRDTN_UseVanillaNotifications)
        {
            m_Notifications.SetVanillaNotifications();
        }
        else
        {
            m_Notifications.SetNotificationLayout(m_CRDTN_Config.CRDTN_NotificationsWrapper, m_CRDTN_Config.CRDTN_Notifications);
        }
    }
}
