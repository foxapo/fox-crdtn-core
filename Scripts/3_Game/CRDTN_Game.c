modded class DayZGame
{
    private ref CRDTN_EventHandler  m_CRDTN_EventHandler        = new CRDTN_EventHandler;
    private ref CRDTN_Config        m_CRDTN_Config              = NULL;

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

        if(IsServer())
        {
            if(!FileExist(CFG_CRDTN_Root_Folder))
            {
                DebugUtils.Log(CFG_CRDTN_Core_Prefix + " Game::DayZGame() Creating new root folder: " + CFG_CRDTN_Root_Folder);
                // Intiialize the folder if necessary 
                MakeDirectory(CFG_CRDTN_Root_Folder);
            }

            m_CRDTN_Config = new CRDTN_Config();
            if(!FileExist(CFG_CRDTN_ConfigPath))
            {
                // Create a new config
                DebugUtils.Log(CFG_CRDTN_Core_Prefix + " Game::DayZGame() Creating new config file: " + CFG_CRDTN_ConfigPath);
                CRDTN_Config.Save(m_CRDTN_Config);
            }
            else
            {
                CRDTN_Config.Load(m_CRDTN_Config);
            }
            CRDTN_Config.Load(m_CRDTN_Config);
        }
    }
    
    CRDTN_EventHandler CRDTNGetEventHandler()
    {
        return m_CRDTN_EventHandler;
    }

    CRDTN_Config GetConfig()
    {
        return m_CRDTN_Config;
    }

    /// @brief Called primarily on the server 
    /// @return 
    override void InitNotifications()
	{
        if(IsServer())
        {
            if(m_CRDTN_Config.CRDTN_UseVanillaNotifications)
            {
                super.InitNotifications();
                return;
            }

            if(m_CRDTN_Config.CRDTN_NotificationsWrapper == "")
            {
                CRDTN_InitNotifications(CFG_CRDTN_NotificationsWrapper);
            }
            else
            {
                CRDTN_InitNotifications(m_CRDTN_Config.CRDTN_NotificationsWrapper);
            }

            if( m_CRDTN_Config.CRDTN_Notifications == "")
            {
                m_Notifications.SetNotificationLayout(CFG_CRDTN_NotificationsLayout);
            }
            else
            {
                m_Notifications.SetNotificationLayout(m_CRDTN_Config.CRDTN_Notifications);
            }
        }

        // Do not call super.InitNotifications() here on the client, this is called later once the config is received. 
	}

    void CRDTN_InitNotifications(string root_path)
    {
        NotificationSystem.InitInstance();
        m_Notifications = new CRDTN_NotificationUI(root_path);
    }

    /// @brief This is mainly called on the client after receiving the config from the server
    void SetCRDTNCoreConfig(ref CRDTN_Config cfg)
    {
        m_CRDTN_Config = cfg;
        if(!IsClient())
        {
            return;
        }

        if(m_CRDTN_Config == null)
        {
            NotificationSystem.InitInstance();
            m_Notifications = new NotificationUI();
            return;
        }
    
        if(m_CRDTN_Config.CRDTN_UseVanillaNotifications)
        {
            NotificationSystem.InitInstance();
            m_Notifications = new NotificationUI();
            return;
        }

        if(m_CRDTN_Config.CRDTN_NotificationsWrapper == "")
        {
            CRDTN_InitNotifications(CFG_CRDTN_NotificationsWrapper);
        }
        else
        {
            CRDTN_InitNotifications(m_CRDTN_Config.CRDTN_NotificationsWrapper);
        }

        if( m_CRDTN_Config.CRDTN_Notifications == "")
        {
            m_Notifications.SetNotificationLayout(CFG_CRDTN_NotificationsLayout);
        }else
        {
            m_Notifications.SetNotificationLayout(m_CRDTN_Config.CRDTN_Notifications);
        }
    }
}
