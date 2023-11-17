class UI_CRDTNMenu extends UIScriptedMenu
{
    protected bool m_IsActive = false;

    protected ImageWidget               m_Background;
    protected GridSpacerWidget          m_NavigationGrid;
    protected GridSpacerWidget          m_ContentGrid;
    protected GridSpacerWidget          m_FooterGrid;
    protected TextWidget                m_ContextHeaderText;
    protected TextWidget                m_ContentHeaderText;

          // Cache
    protected ref array<ref Widget> m_NavigationCategories  = new array<ref Widget>();
    protected ref array<ref Widget> m_CurrentContentWidgets = new array<ref Widget>();
    
          // Events
    ref ScriptInvoker EEntrySelected;

          // Selected entry
    protected ref UI_CRDTNListEntry       m_SelectedEntry;


    override Widget Init()
    {
        layoutRoot = GetGame().GetWorkspace().CreateWidgets(GetCRDTNMenuLayout());

        m_Background        = ImageWidget.Cast(layoutRoot.FindAnyWidget("Background"));
        m_NavigationGrid    = GridSpacerWidget.Cast(layoutRoot.FindAnyWidget("NavigationGrid"));
        m_ContentGrid       = GridSpacerWidget.Cast(layoutRoot.FindAnyWidget("ContentGrid"));
        m_FooterGrid        = GridSpacerWidget.Cast(layoutRoot.FindAnyWidget("FooterGrid"));
        m_ContextHeaderText = TextWidget.Cast(layoutRoot.FindAnyWidget("ContextHeaderText"));
        m_ContentHeaderText = TextWidget.Cast(layoutRoot.FindAnyWidget("ContentHeaderText"));

        InitLayout();
        InitCache();
        RegisterListeners();

        return layoutRoot;
    }

    string GetCRDTNMenuLayout()
    {
        return CFG_CRDTN_UI_Menu_Layout;
    }

    void InitLayout();

    void InitCache()
    {
        ClearCategories();
    }

    void ClearCategories()
    {        
        if(m_NavigationCategories)
        {
            foreach(Widget widget : m_NavigationCategories)
            {
                m_NavigationGrid.RemoveChild(widget);
            }
            m_NavigationCategories.Clear();
        }
    }

    void UI_OnListEntrySelected(ref UI_CRDTNListEntry listEntry)
    {
              // Prevents of clicking on the same entry twice
        if(m_SelectedEntry != NULL && m_SelectedEntry == listEntry) 
        {
            return;
        }

        if(m_SelectedEntry != NULL)
        {
            m_SelectedEntry.Select(false);
        }

        m_SelectedEntry = listEntry;
        m_SelectedEntry.Select(true);

        if(m_CurrentContentWidgets)
        {
            ClearContentData();
        }
        else
        {
            m_CurrentContentWidgets = new array<ref Widget>();
        }

        InitEntryData(listEntry.ContextData);
    }

    void InitContext(CRDTN_EMenuContext context)
    {
        InitMain(context);
        InitNavigation(context);
        if(m_SelectedEntry != null)
        {
            UI_OnListEntrySelected(m_SelectedEntry);
        }
        else
        {
            InitContent(context);
        }
    }

    void InitMain(CRDTN_EMenuContext context);

    void InitNavigation(CRDTN_EMenuContext context);

    void InitContent(CRDTN_EMenuContext context);

    void InitContextData(Param data, CRDTN_EMenuContext context);

    void InitEntryData(ref Param data);

    void ShowMenu(CRDTN_EMenuContext context = CRDTN_EMenuContext._NONE)
    {
        if (!IsShowing() && GetGame().GetUIManager().GetMenu() == NULL)
        {
            UI_CRDTNMenu menu = UI_CRDTNMenu.Cast(GetGame().GetUIManager().ShowScriptedMenu(this, NULL));
            if (menu)
            {
                m_IsActive = true;
                menu.InitContext(context);
            }
        }
    }

    void ShowMenuWithData(CRDTN_EMenuContext context = CRDTN_EMenuContext._NONE, Param data = NULL)
    {
        if (!IsShowing() && GetGame().GetUIManager().GetMenu() == NULL)
        {
            UI_CRDTNMenu menu = UI_CRDTNMenu.Cast(GetGame().GetUIManager().ShowScriptedMenu(this, NULL));
            if (menu)
            {
                m_IsActive = true;
                menu.InitContextData(data, context);
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

    void RegisterListeners()
    {
        if(!EEntrySelected)
        {
            EEntrySelected = new ScriptInvoker();
            EEntrySelected.Insert(UI_OnListEntrySelected);
        }
    }

    void UnRegisterListeners()
    {
        if(EEntrySelected)
        {
            EEntrySelected.Clear();
        }
    }

    bool IsShowing()
    {
        return m_IsActive;
    }

    override void OnShow()
    {
        super.OnShow();
        RegisterListeners();
        LockPlayerControl();
    }

    override void OnHide()
    {
        super.OnHide();
        UnRegisterListeners();
        UnlockPlayerControl();
    }

    // Widgets helpers

    protected Widget AddDivider()
    {
        Widget divider = GetGame().GetWorkspace().CreateWidgets(CFG_CRDTN_UI_Menu_Element_Divider, m_ContentGrid);
        m_CurrentContentWidgets.Insert(divider);
        return divider;
    }

    protected MultilineTextWidget AddBodyHeader(string text)
    {
        Widget              header     = GetGame().GetWorkspace().CreateWidgets(CFG_CRDTN_UI_Menu_Element_Header, m_ContentGrid);
        MultilineTextWidget headerText = MultilineTextWidget.Cast(header);
        headerText.SetText(text);
        m_CurrentContentWidgets.Insert(header);
        return headerText;
    }


    protected MultilineTextWidget AddBodyText(string text)
    {
        Widget              body     = GetGame().GetWorkspace().CreateWidgets(CFG_CRDTN_UI_Menu_Element_Text, m_ContentGrid);
        MultilineTextWidget bodyText = MultilineTextWidget.Cast(body);
        bodyText.SetText(text);
        m_CurrentContentWidgets.Insert(body);
        return bodyText;
    }

    protected GridSpacerWidget AddNavigationCategory(string text)
    {
        Widget category = GetGame().GetWorkspace().CreateWidgets(CFG_CRDTN_UI_Menu_Category, m_NavigationGrid);
        m_NavigationCategories.Insert(category);
        TextWidget categoryText = TextWidget.Cast(category.FindAnyWidget("CategoryName"));
        categoryText.SetText(text);
        GridSpacerWidget categoryGrid = GridSpacerWidget.Cast(category.FindAnyWidget("CategoryEntries"));
        return categoryGrid;
    }

    protected UI_CRDTNListEntry AddListEntry(ref GridSpacerWidget navigationCategory, string primaryText = "", string secondaryText = "", string entryIconPath = "")
    {
        UI_CRDTNListEntry listEntry;
        Widget entryWidget = GetGame().GetWorkspace().CreateWidgets(CFG_CRDTN_UI_Menu_ListEntry, navigationCategory);
        entryWidget.GetScript(listEntry);
        listEntry.SetData(primaryText, secondaryText, entryIconPath, EEntrySelected);
        return listEntry;
    }

    protected void ClearContentData()
    {
        if(m_CurrentContentWidgets)
        {
            foreach(Widget widget : m_CurrentContentWidgets)
            {
                m_ContentGrid.RemoveChild(widget);
            }
            m_CurrentContentWidgets.Clear();
        }
    }
};