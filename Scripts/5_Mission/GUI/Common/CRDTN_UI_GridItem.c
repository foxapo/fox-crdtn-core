class CRDTN_UI_GridItem
{
	protected ref CRDTN_UI_Grid m_ParentGrid;
	protected Widget m_Root;
	protected Widget m_Selected;
	protected InventoryItem m_Item;
	protected ref Managed m_Parent;
	protected ref InventoryLocation m_InventoryLocation;
	protected float m_CellSize;
	protected bool m_IsFlipped;
	protected Widget m_EventButtonWidget;
	protected ref CRDTN_EventHandlerButton m_EventButton;
	protected ImageWidget _backgroundImage;
	protected ItemPreviewWidget m_ItemPreview;
	protected EContainerType _containerType;
	protected bool _initialized = false;

	ref ScriptInvoker EventMouseEnter = new ScriptInvoker();
	ref ScriptInvoker EventMouseLeave = new ScriptInvoker();
	ref ScriptInvoker EventMouseClick = new ScriptInvoker();
		
	void CRDTN_UI_GridItem(ref CRDTN_UI_Grid grid, InventoryItem item, Widget parent, float size)
	{
		m_ParentGrid = grid;
		m_Item       = item;
		m_CellSize   = size;
		m_Parent     = parent;
		m_Root       = GetGame().GetWorkspace().CreateWidgets(GetLayoutPath(), m_Parent);
		m_Root.GetScript(m_EventButton);
		m_ItemPreview     = ItemPreviewWidget.Cast(m_Root.FindAnyWidget("ItemPreview"));
		m_Selected        = m_Root.FindAnyWidget("Selected");
		// override this to add more elements
		InitializeAdditionalElements();

		EventMouseEnter.Insert(UI_OnMouseEnter);
		EventMouseLeave.Insert(UI_OnMouseLeave);
		EventMouseClick.Insert(UI_OnMouseClick);

		m_EventButton.SetEventInvokers(EventMouseClick, EventMouseEnter, EventMouseLeave);
		m_EventButton.SetEventData(new Param1<InventoryItem>(m_Item));

		InitItemPreview();
	}

	/// @brief Additional helper method for convenience to register additional elements
	void InitializeAdditionalElements()
	{
		_backgroundImage = ImageWidget.Cast(m_Root.FindAnyWidget("BG"));
	}

	void DestroyObject()
	{
		if (m_Item)
			m_Item.GetOnItemFlipped().Remove(UpdateFlip);

		m_Item = NULL;

		if (EventMouseEnter)
			EventMouseEnter.Clear();

		if (EventMouseLeave)
			EventMouseLeave.Clear();

		if (EventMouseClick)
			EventMouseClick.Clear();

		delete m_EventButton;
		m_Root.Unlink();
	}

	/// @brief Layout path - override if necessary with your custom layout path 
	/// @return 
	string GetLayoutPath()
	{
		return CFG_CRDTN_UI_Layout_Grid_Item;
	}

	void InitItemPreview()
	{

		if (!_initialized)
		{
			m_ItemPreview.SetItem(m_Item);
			m_Item.GetOnItemFlipped().Insert(UpdateFlip);
			_initialized = true;
		}

		m_InventoryLocation = new InventoryLocation;
		m_Item.GetInventory().GetCurrentInventoryLocation(m_InventoryLocation);
		float widht, height;
		m_Root.GetSize(widht, height);
		int col = m_InventoryLocation.GetCol();
		int row = m_InventoryLocation.GetRow();
		SetPos(col, row);
		float x, y;
		m_Root.GetPos(x, y);
		m_IsFlipped = m_Item.GetInventory().GetFlipCargo();
		UpdateFlip();
	}

	void InitContainerContext(EContainerType containerType)
	{
		_containerType = containerType;
		// Override here and add new logic 
	}

	EntityAI GetEntity()
	{
		return m_Item;
	}

	//! POSITION & SIZE !//

	void SetCellSize(float size)
	{
		if (m_CellSize != size)
		{
			m_CellSize = size;

			int w, h;
			GetSize(w, h);
			SetSize(w, h);
		}
	}

	void SetPos(int col, int row)
	{
		col = Math.Max(col, 0);
		row = Math.Max(row, 0);

		m_InventoryLocation.SetCol(col);
		m_InventoryLocation.SetRow(row);

		m_Root.SetPos(m_CellSize * col, m_CellSize * row);
	}

	void SetSize(int w, int h)
	{
		m_Root.SetSize(m_CellSize * w, m_CellSize * h);
	}

	void GetSize(out int w, out int h)
	{
		int inv_w, inv_h;
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

		if (!m_IsFlipped)
			SetSize(w, h);
		else
			SetSize(h, w);

		m_ItemPreview.SetForceFlip(m_IsFlipped);
	}

	  // ! EVENTS ! //

	void UI_OnMouseEnter(int x, int y)
	{
		m_Selected.Show(true);
	}

	void UI_OnMouseLeave(int x, int y)
	{
		m_Selected.Show(false);
	}

	void UI_OnMouseClick(Param data)
	{
		// IMPLEMENT YOUR LOGIC HERE
	}
};