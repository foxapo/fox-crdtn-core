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

        #ifdef CRDTN_Krabice
        Print(CFG_CRDTN_Core_Prefix + " Game::DayZGame() CRDTN_KRABICE enabled");
        #endif

        #ifdef CRDTN_Rad
        Print(CFG_CRDTN_Core_Prefix + " Game::DayZGame() CRDTN_Radiation enabled");
        #endif

        #ifdef CRDTN_LockedDoors
        Print(CFG_CRDTN_Core_Prefix + " Game::DayZGame() CRDTN_LockedDoors enabled");
        #endif

        #ifdef CRDTN_Creatures
        Print(CFG_CRDTN_Core_Prefix + " Game::DayZGame() CRDTN_Creatures enabled");
        #endif

        m_CRDTN_EventHandler = new CRDTN_EventHandler();

        if(!FileExist(CFG_CRDTN_Root_Folder))
        {
            DebugUtils.Log(CFG_CRDTN_Core_Prefix + " Game::DayZGame() Creating new root folder: " + CFG_CRDTN_Root_Folder);
            MakeDirectory(CFG_CRDTN_Root_Folder);
        }

        if(!FileExist(CFG_CRDTN_DataFolder))
        {
            DebugUtils.Log(CFG_CRDTN_Core_Prefix + " Game::DayZGame() Creating new data folder: " + CFG_CRDTN_DataFolder);
            MakeDirectory(CFG_CRDTN_DataFolder);
        }

        if(IsServer() && !IsClient())
        {
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

        CRDTN_OnGameInit();
    }

    // Use this for override to do some magic after game init
    void CRDTN_OnGameInit();
    
    CRDTN_EventHandler CRDTNGetEventHandler()
    {
        return m_CRDTN_EventHandler;
    }

    CRDTN_Config CRDTN_GetConfig()
    {
        return m_CRDTN_Config;
    }

    /// @brief This is mainly called on the client after receiving the config from the server
    void SetCRDTNCoreConfig(ref CRDTN_Config cfg)
    {
        m_CRDTN_Config = cfg;
    }
};
