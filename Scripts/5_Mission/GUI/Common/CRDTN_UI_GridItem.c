class CRDTN_UI_GridItem
{
    protected Widget m_Root;
	protected Widget m_Selected;
    protected InventoryItem m_Item;
    protected ItemPreviewWidget m_ItemPreview;
    protected TextWidget m_Counter;
    protected ref Managed m_Parent;
    protected ref InventoryLocation m_InventoryLocation;
	protected float m_CellSize;
    protected bool m_IsFlipped;

	private ref ScriptInvoker EventMouseEnter = new ScriptInvoker();
	private ref ScriptInvoker EventMouseLeave = new ScriptInvoker();
	private ref ScriptInvoker EventClick      = new ScriptInvoker();

	private Widget m_EventButtonWidget;
	private ref CRDTN_EventHandlerButton m_EventButton;

    void CRDTN_UI_GridItem(InventoryItem item, Widget parent, float size)
    {

		m_Item        = item;
		m_CellSize    = size;
		m_Parent      = parent;
		
		m_Root        = GetGame().GetWorkspace().CreateWidgets(GetLayoutPath(), m_Parent);
		m_Root.GetScript(m_EventButton);

		m_ItemPreview = ItemPreviewWidget.Cast(m_Root.FindAnyWidget("ItemPreview"));
		m_Counter     = TextWidget.Cast(m_Root.FindAnyWidget("Counter"));
		m_Selected    = m_Root.FindAnyWidget("Selected");

		m_EventButton.InitButton();
		m_EventButton.EClick.Insert(UI_OnClick);
		m_EventButton.EMouseEnter.Insert(UI_OnMouseEnter);
		m_EventButton.EMouseLeave.Insert(UI_OnMouseLeave);

        InitItemPreview();
		UpdateInfo();
    }

	// void ~CRDTN_UI_GridItem()
	// {
	// 	m_Item.GetOnItemFlipped().Remove( UpdateFlip );
	// 	m_Root.Unlink();
	// 	delete m_EventButton;
	// }

	string GetLayoutPath()
	{
		return CFG_CRDTN_UI_Layout_Grid_Item;
	}

    void InitItemPreview()
    {
		DebugUtils.Log("CRDTN_UI_GridItem::InitItemPreview of " + m_Item.GetType());
		m_ItemPreview.SetItem(m_Item);
        m_InventoryLocation = new InventoryLocation;
        m_Item.GetInventory().GetCurrentInventoryLocation(m_InventoryLocation);

        float widht, height;
        m_Root.GetSize( widht, height );

		int col = m_InventoryLocation.GetCol();
		int row = m_InventoryLocation.GetRow();

		SetPos(col, row);
		
		float x,y;
		m_Root.GetPos(x,y);
		
		m_Item.GetOnItemFlipped().Insert( UpdateFlip );
		
		m_IsFlipped = m_Item.GetInventory().GetFlipCargo();
		UpdateFlip();
    }

	void UpdateInfo()
	{
		int randomPrice = Math.RandomInt(1, 100);
		m_Counter.SetText(randomPrice.ToString() + "$");
	}

	EntityAI GetEntity()
	{
		return m_Item;
	}

	//! POSITION & SIZE !//

    void SetCellSize(float size)
	{
		if(m_CellSize != size)
		{
			m_CellSize = size;
		
			int w, h;
			GetSize(w, h);
			SetSize(w, h);
		}
	}

    void SetPos(int col, int row )
	{
		col = Math.Max(col, 0);
		row = Math.Max(row, 0);
		
		m_InventoryLocation.SetCol(col);
		m_InventoryLocation.SetRow(row);
		
        m_Root.SetPos( m_CellSize * col, m_CellSize * row );
	}
	
	void SetSize(int w, int h)
	{
        m_Root.SetSize( m_CellSize * w, m_CellSize * h);
	}
	
	void GetSize(out int w, out int h)
	{
		int inv_w,inv_h;
		GetGame().GetInventoryItemSize(m_Item, w, h);
	}

      //! FLIP !//

    void Flip()
	{
		m_IsFlipped = !m_IsFlipped;
		UpdateFlip();
	}
	
	bool GetFlip()
	{
		return m_IsFlipped;
	}

    void UpdateFlip()
	{
		int w, h;
		GetSize(w, h);

		if(!m_IsFlipped)
			SetSize(w, h);
		else
			SetSize(h, w);
		
		m_ItemPreview.SetForceFlip(m_IsFlipped);
	}

	  // ! EVENTS ! //

	void UI_OnMouseEnter()
	{
		m_Selected.Show(true);
	}

	void UI_OnMouseLeave()
	{
		m_Selected.Show(false);
	}

	// void DoubleClick(Widget w, int x, int y, int button)
	// {
	// 	if( button == MouseState.LEFT && !g_Game.IsLeftCtrlDown())
	// 	{
	// 		  // DO something with ctrl 
	// 	}

	// 	return;
	// }

	void UI_OnClick()
	{
		CRDTN_GetTradingEvent(CRDTN_Trading_Stock_Product_MouseClick).Invoke(this);
	}
};