class UI_CRDTNButton extends ScriptedWidgetEventHandler
{
    private         ButtonWidget        m_EntryButton;
    private         Widget              m_Root;
    protected       ImageWidget         m_Icon;
    protected       ImageWidget         m_Selected;
    private         string              _EntryIcon;
    
    ref             ScriptInvoker       EOnSelect;
    ref             Param               ContextData;

    void OnInit(ref Param param)
    {
        ContextData = param;
    }

    void OnWidgetScriptInit(Widget w)
    {
        m_Root        = w;
        m_EntryButton = ButtonWidget.Cast(m_Root.FindAnyWidget("Button"));
        m_Icon        = ImageWidget.Cast(m_Root.FindAnyWidget("ButtonIcon"));
        m_Selected    = ImageWidget.Cast(m_Root.FindAnyWidget("Selected"));
        Select(false);
        w.SetHandler(this);
    }

    void SetData(string entryIconPath, ref ScriptInvoker listEntrySelected)
    {
        if (entryIconPath == "")
        {
            _EntryIcon = "CRDTN_Quests/data/images/icons/50.edds";
        }
        else
        {
            _EntryIcon = entryIconPath;
        }
        EOnSelect = listEntrySelected;
        RefreshUI();
    }

    void SetSelectedCallback(ref ScriptInvoker selectedCallback)
    {
        EOnSelect = selectedCallback;
    }

    void RefreshUI()
    {
        m_Icon.LoadImageFile(0, _EntryIcon);
        m_Icon.SetImage(0);
    }

    override bool OnMouseButtonDown(Widget w, int x, int y, int button)
    {
        if (w == m_EntryButton)
        {
            if (!EOnSelect)
            {
                return false;
            }

            if (button == MouseState.LEFT)
            {
                EOnSelect.Invoke(this);
            }
            else if (button == MouseState.RIGHT)
            {
                    // TODO: complete here
            }
            return true;
        }
        return super.OnClick(w, x, y, button);
    }

    override bool OnMouseEnter(Widget w, int x, int y)
	{
        if(w == m_EntryButton)
        {
            Select(true);
        }

        
        return true;
	}

	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
        if(w == m_EntryButton)
        {
            Select(false);
        }

        return true;
    }


    void Select(bool state)
    {
        if (!m_Selected)
        {
            return;
        }
        m_Selected.Show(state);
    }
};