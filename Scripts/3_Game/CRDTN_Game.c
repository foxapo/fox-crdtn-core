modded class DayZGame
{
    private ref CRDTN_EventHandler m_CRDTN_EventHandler;
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
}
