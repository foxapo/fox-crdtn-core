class CRDTN_UI_CargoContainer
{
    protected Widget m_ParentWidget;
    protected EntityAI m_CargoEntity;
    protected EntityAI m_CargoOwner;
    protected CargoBase m_Cargo;
    protected ref CRDTN_UI_Grid m_Grid;

    void CRDTN_UI_CargoContainer(Widget parent, EntityAI ent)
    {
        m_ParentWidget = parent;
        m_CargoEntity = ent;
        m_Cargo = ent.GetInventory().GetCargo();
        m_CargoOwner = m_Cargo.GetCargoOwner();
        m_CargoOwner.GetOnItemAddedIntoCargo().Insert(AddCargo);
        m_CargoOwner.GetOnItemRemovedFromCargo().Insert(RemoveCargo);
        m_Grid = new CRDTN_UI_Grid(m_ParentWidget, m_Cargo.GetWidth(), m_Cargo.GetHeight());
        m_ParentWidget.Show(true);
        Initialize();
    }

    void Initialize()
    {
        if(!m_Cargo)
        {
            DebugUtils.Log("CRDTN_UI_CargoContainer::Initialize - No cargo");
        }

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
        
    }


};


class CRDTN_UI_PlayerCargoContainer : CRDTN_UI_CargoContainer
{

    void CRDTN_UI_PlayerCargoContainer(Widget parent, EntityAI ent)
    {
        m_ParentWidget = parent;
        m_CargoEntity = ent;
        m_Cargo = ent.GetInventory().GetCargo();
        m_CargoOwner = m_Cargo.GetCargoOwner();
        m_CargoOwner.GetOnItemAddedIntoCargo().Insert(AddCargo);
        m_CargoOwner.GetOnItemRemovedFromCargo().Insert(RemoveCargo);
        m_Grid = new CRDTN_UI_Grid(m_ParentWidget, m_Cargo.GetWidth(), m_Cargo.GetHeight());
        m_ParentWidget.Show(true);
        Initialize();
    }

    override void Initialize()
    {
        if(!m_Cargo)
        {
            DebugUtils.Log("CRDTN_UI_PlayerCargoContainer::Initialize - No cargo");
        }        

     
        for(int i = 0; i < objects.Count(); i++)
        {
            EntityAI item = objects.Get(i);
            if(!item)
            {
                continue;
            }
            m_Grid.AddToGrid(item);
        }
    }
};