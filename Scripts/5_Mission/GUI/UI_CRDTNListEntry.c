class UI_CRDTNListEntry extends ScriptedWidgetEventHandler
{
    private ButtonWidget    m_EntryButton;
    private Widget          m_Root;

    protected TextWidget    m_PrimaryText;
    protected TextWidget    m_SecondaryText;
    protected ImageWidget   m_EntryIcon;
    protected ImageWidget   m_Selected;

    private string          _PrimaryText;
    private string          _SecondaryText;
    private string          _EntryIcon;

    ref ScriptInvoker EListEntrySelected = new ScriptInvoker();
    ref Param ContextData;

    void OnInit(ref Param param)
    {
        ContextData = param;
    }
    // ~void OnDestroy()
    // {
    //     if(EListEntrySelected)
    //         EListEntrySelected.Clear();
    // }

    void OnWidgetScriptInit(Widget w)
	{
        m_Root = w;
        m_EntryButton               = ButtonWidget.Cast(m_Root.FindAnyWidget("Button"));
        m_PrimaryText               = TextWidget.Cast(m_Root.FindAnyWidget("PrimaryText"));
        m_SecondaryText             = TextWidget.Cast(m_Root.FindAnyWidget("SecondaryText"));
        m_EntryIcon                 = ImageWidget.Cast(m_Root.FindAnyWidget("EntryIcon"));
        m_Selected                  = ImageWidget.Cast(m_Root.FindAnyWidget("Selected"));
        Select(false);
		w.SetHandler(this);
	}

    void SetData(string primaryText, string secondaryText, string entryIconPath)
    {
        _PrimaryText               = primaryText;
        _SecondaryText             = secondaryText;
        _EntryIcon                 = entryIconPath;
        RefreshUI();
    }
   
    void RefreshUI()
    {
        m_PrimaryText.SetText(_PrimaryText);
        m_SecondaryText.SetText(_SecondaryText);
        m_EntryIcon.LoadImageFile(0, _EntryIcon);
        m_EntryIcon.SetImage(0);
    }

    override bool OnMouseButtonDown(Widget w, int x, int y, int button)
    {
		if (w == m_EntryButton)
		{
			if(!EListEntrySelected)
            {
                return false;
            }

            if(button == MouseState.LEFT)
            {
                EListEntrySelected.Invoke(this);
            }
            else if(button == MouseState.RIGHT)
            {
                // TODO: complete here
            }
			return true;
		}
		return super.OnClick(w, x, y, button);
    }
  
    void Select(bool state)
    {
        if(!m_Selected)
        {
            return;
        }
        m_Selected.Show(state);
    }
};