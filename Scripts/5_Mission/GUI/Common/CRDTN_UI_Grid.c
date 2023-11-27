class CRDTN_UI_Grid
{
    private Widget m_Root;
    private Widget m_Parent;
    private Widget m_Content;
    private Widget m_GridSpacer;
    private Widget m_Wrapper;
    private int m_Width;
    private int m_Height;
    private ref CRDTN_UI_CargoContainer m_Container;
    private ref map<ref Vector2, ref CRDTN_UI_GridItem> m_Items;

    private float m_GridCellSize;

    void CRDTN_UI_Grid(Widget parent, int width, int height)
    {
        m_Parent  = parent;
        m_Root    = GetGame().GetWorkspace().CreateWidgets(GetRootLayoutPath(), m_Parent);
        m_Content = m_Root.FindAnyWidget("Content");
        m_GridSpacer = m_Root.FindAnyWidget("Grid");
        m_Width   = width;
        m_Height  = height;

        InitItemData();
        DrawRows();
    }

    string GetRootLayoutPath()
    {
        return CFG_CRDTN_UI_Layout_Grid_Wrapper;
    }

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
        m_Items = new map<ref Vector2, ref CRDTN_UI_GridItem>();
        for (int x = 0; x < m_Width; x++)
        {
            for (int y = 0; y < m_Height; y++)
            {
                m_Items.Insert(new Vector2(x, y), null);
            }
        }
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
        DebugUtils.Log("CRDTN_UI_Grid::AddToGrid " + ent);
        InventoryItem item;
		if(Class.CastTo(item, ent))
		{
            DebugUtils.Log("CRDTN_UI_Grid::AddToGrid-InventoryItem " + item);
            CRDTN_UI_GridItem gridItem  = new CRDTN_UI_GridItem(item, m_Content, m_GridCellSize);
        }
    }

};