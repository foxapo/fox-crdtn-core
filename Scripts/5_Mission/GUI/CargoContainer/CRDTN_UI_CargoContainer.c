class CRDTN_UI_CargoContainer
{
    protected Widget m_ParentWidget;
    protected EntityAI m_CargoEntity;
    protected EntityAI m_CargoOwner;
    protected CargoBase m_Cargo;
    protected ref CRDTN_UI_Grid m_Grid;

    private string m_EventOnClick;
    private ref ScriptInvoker EOnGridItemClicked;

    void CRDTN_UI_CargoContainer(Widget parent, EntityAI ent, string ON_CLICK_EVENT = "")
    {
        m_ParentWidget = parent;
        m_CargoEntity = ent;
        m_Cargo = ent.GetInventory().GetCargo();
        m_CargoOwner = m_Cargo.GetCargoOwner();
        m_CargoOwner.GetOnItemAddedIntoCargo().Insert(AddCargo);
        m_CargoOwner.GetOnItemRemovedFromCargo().Insert(RemoveCargo);
        m_Grid = new CRDTN_UI_Grid(m_ParentWidget, m_Cargo.GetWidth(), m_Cargo.GetHeight(), this);
        m_EventOnClick = ON_CLICK_EVENT;
        EOnGridItemClicked = new ScriptInvoker();
        EOnGridItemClicked.Insert(OnGridItemClicked);
        m_ParentWidget.Show(true);
        Initialize();
    }

    ref ScriptInvoker GetClickEvent()
    {
        return EOnGridItemClicked;
    }

    void Initialize()
    {
        // if(!m_Cargo)
        // {
            // DebugUtils.Log("CRDTN_UI_CargoContainer::Initialize - No cargo");
        // }

        for(int i = 0; i < m_Cargo.GetItemCount(); i++)
        {
            EntityAI item = m_Cargo.GetItem(i);
            if(!item)
            {
                continue;
            }
            m_Grid.AddToGrid(item);
        }
        m_Grid.Resize();
    }

    void ~CRDTN_UI_CargoContainer()
    {
        if(m_CargoOwner)
        {
            m_CargoOwner.GetOnItemAddedIntoCargo().Remove(AddCargo);
            m_CargoOwner.GetOnItemRemovedFromCargo().Remove(RemoveCargo);
        }
        delete m_Grid;
    }

    EntityAI GetCargoEntity()
    {
        return m_CargoOwner;
    }

    CargoBase GetCargo()
    {
        return m_Cargo;
    }

    void AddCargo(EntityAI ent)
    {
        m_Grid.AddToGrid(ent);
    }

    void RemoveCargo(EntityAI ent)
    {
        m_Grid.RemoveFromGrid(ent);
    }

    void OnGridItemClicked(ref Param data)
    {
        
        autoptr Param1<InventoryItem> param = Param1<InventoryItem>.Cast(data);
        if(!param)
        {
            // DebugUtils.Log("CRDTN_UI_CargoContainer::OnGridItemClicked - No param");
            return;
        }

        InventoryItem item = param.param1;

        if(m_EventOnClick != "")
        {
            GetDayZGame().CRDTNGetEventHandler().GetEventInvoker(m_EventOnClick).Invoke(item);
        }
        else
        {
            // DebugUtils.Log("CRDTN_UI_CargoContainer::OnGridItemClicked - No event set");
        }
    }

};