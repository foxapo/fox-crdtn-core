class UI_CRDTNMenu extends UIScriptedMenu
{

    protected bool m_IsActive = false;

    void UI_OnListEntrySelected(ref UI_CRDTNListEntry listEntry);

    void UpdateUI();

    void ShowMenu()
    {
        if (!m_IsActive && GetGame().GetUIManager().GetMenu() == NULL)
        {
            UI_CRDTNMenu menu = UI_CRDTNMenu.Cast(GetGame().GetUIManager().ShowScriptedMenu(this, NULL));
            if (menu)
            {
                m_IsActive = true;
                UpdateUI();
            }
        }
    }

    void HideMenu()
    {
        if (GetGame().GetUIManager().GetMenu() == NULL)
        {
            return;
        }

        GetGame().GetUIManager().HideScriptedMenu(this);
        m_IsActive = false;
    }

    void LockPlayerControl()
    {
        PPEffects.SetBlurDrunk(0.9);
        GetGame().GetMission().PlayerControlDisable(INPUT_EXCLUDE_ALL);
        GetGame().GetUIManager().ShowUICursor(true);
    }

    void UnlockPlayerControl()
    {
        PPEffects.SetBlurDrunk(0);
        GetGame().GetMission().PlayerControlEnable(true);
        GetGame().GetInput().ResetGameFocus();
        GetGame().GetUIManager().ShowUICursor(false);
    }

    bool IsShowing()
    {
        return m_IsActive;
    }

    override void OnShow()
    {
        super.OnShow();
        LockPlayerControl();
    }

    override void OnHide()
    {
        super.OnHide();
        UnlockPlayerControl();
    }

};