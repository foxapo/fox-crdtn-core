class CRDTN_UI_Grid
{
    protected Widget m_Root;
    protected Widget m_Parent;
    protected Widget m_Content;
    protected Widget m_GridSpacer;
    protected Widget m_Wrapper;
    protected int m_Width;
    protected int m_Height;
    protected ref CRDTN_UI_CargoContainer m_Container;
    protected ref map<EntityAI, ref CRDTN_UI_GridItem> m_Items;
    protected float m_GridCellSize;

    void CRDTN_UI_Grid(Widget parent, int width, int height, ref CRDTN_UI_CargoContainer container = null)
    {
        m_Parent  = parent;
        m_Root    = GetGame().GetWorkspace().CreateWidgets(GetRootLayoutPath(), m_Parent);
        m_Content = m_Root.FindAnyWidget("Content");
        m_GridSpacer = m_Root.FindAnyWidget("Grid");
        m_Width   = width;
        m_Height  = height;
        m_Container = container;
        Initialize();
    }

    /// @brief Should be run upon construction
    void Initialize()
    {
        InitItemData();
        DrawRows();
    }

    ref ScriptInvoker GetClickEvent()
    {
        return m_Container.GetClickEvent();
    }

    /// @brief Can be overriden to change the layout path
    string GetRootLayoutPath()
    {
        return CFG_CRDTN_UI_Layout_Grid_Wrapper;
    }

    /// @brief Can be overriden to change the layout path
    string GetRowLayoutPath()
    {
        return CFG_CRDTN_UI_Layout_Grid_Row;
    }

    void ~CRDTN_UI_Grid()
    {
        delete m_Items;
        m_Root.Unlink();
    }

    int GetWidth()
    {
        return m_Width;
    }

    int GetHeight()
    {
        return m_Height;
    }

    float GetCellSize()
    {
        return m_GridCellSize;
    }

    void InitItemData()
    {
        m_Items = new map<EntityAI, ref CRDTN_UI_GridItem>();
    }

    void DrawRows()
    {
        for (int y = 0; y < m_Height; y++)
        {
            Widget row = GetGame().GetWorkspace().CreateWidgets(GetRowLayoutPath(), m_GridSpacer);
            float h;
            row.GetSize(h, m_GridCellSize);
        }
    }

    void Resize()
    {
        if( m_Content.IsVisible() )
		{
			autoptr SizeToChild handler;
			m_Content.GetScript(handler);
			bool result;
			handler.ResizeParentToChild(result);
		}
    }

    void AddToGrid(EntityAI ent)
    {
        // DebugUtils.Log("CRDTN_UI_Grid::AddToGrid " + ent);
        InventoryItem item;
		if(Class.CastTo(item, ent))
		{
            // DebugUtils.Log("CRDTN_UI_Grid::AddToGrid-InventoryItem " + item);
            CRDTN_UI_GridItem gridItem  = new CRDTN_UI_GridItem(this, item, m_Content, m_GridCellSize);
            m_Items.Insert(ent, gridItem);
        }
    }

    void RemoveFromGrid(EntityAI ent)
    {
        // DebugUtils.Log("CRDTN_UI_Grid::RemoveFromGrid " + ent);
        if(m_Items.Contains(ent))
        {
            CRDTN_UI_GridItem gridItem = m_Items.Get(ent);
            m_Items.Remove(ent);
            delete gridItem;
        }
    }


};