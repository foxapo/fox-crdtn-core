modded class MissionGameplay
{
    
    ref CRDTN_PlayerMenu m_CRDTN_PlayerMenu;
    override void OnKeyPress(int key)
    {
        super.OnKeyPress(key);
        switch (key)
        {
        case KeyCode.KC_ESCAPE:
            if (GetCRDTN_CorePlugin())
            {
                CloseCRDTN_Menu();
            }
            break;
        case KeyCode.KC_K:
            if (GetCRDTN_CorePlugin())
            {
                OpenCRDTN_Menu();
            }
            break;
        }
    }

    void CloseCRDTN_Menu()
    {
        CRDTN_PlayerMenu menu = CRDTN_PlayerMenu.Cast(GetGame().GetUIManager().GetMenu());
        if (menu)
        {
            menu.HideMenu();
        }
    }

    void OpenCRDTN_Menu()
    {
        if(GetGame().GetUIManager().GetMenu() != NULL)
        {
            // Prevent from openiong the menu if another menu is already open
            return;
        }

        if (!m_CRDTN_PlayerMenu)
        {
            m_CRDTN_PlayerMenu = new CRDTN_PlayerMenu();
        }

        if(!m_CRDTN_PlayerMenu)
        {
            return;
        }

        if(m_CRDTN_PlayerMenu.IsShowing())
        {
            return;
        }

        m_CRDTN_PlayerMenu.ShowMenu(CRDTN_EMenuContext.PLAYER);
    }
};
