class CRDTN_UI_CargoContainer
{
    protected Widget m_ParentWidget;
    protected EntityAI m_CargoEntity;
    protected EntityAI m_CargoOwner;
    protected CargoBase m_Cargo;
    protected ref CRDTN_UI_Grid m_Grid;
    protected bool _isPlayer = false;

    protected EContainerType _containerType;

    void CRDTN_UI_CargoContainer(Widget parent, EntityAI ent, EContainerType containerType, string ON_CLICK_EVENT = "", bool isPlayer = false)
    {
        m_ParentWidget = parent;
        
        _isPlayer = isPlayer;
        _containerType = containerType;

        m_CargoEntity = ent;
        m_Cargo = ent.GetInventory().GetCargo();
        m_CargoOwner = m_Cargo.GetCargoOwner();
        m_CargoOwner.GetOnItemAddedIntoCargo().Insert(AddCargo);
        m_CargoOwner.GetOnItemRemovedFromCargo().Insert(RemoveCargo);
        m_Grid = new CRDTN_UI_Grid(m_ParentWidget, m_Cargo.GetWidth(), m_Cargo.GetHeight(), this);
    
        m_ParentWidget.Show(true);

        Initialize();
    }

    void Initialize()
    {
        for(int k = 0; k < m_Cargo.GetItemCount(); k++)
        {
            EntityAI item = m_Cargo.GetItem(k);
            if(!item)
            {
                continue;
            }
            autoptr CRDTN_UI_GridItem gridItem = m_Grid.AddToGrid(item);
            gridItem.InitContainerContext(_containerType);
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
        if(!ent)
        {
            return;
        }
        autoptr CRDTN_UI_GridItem gridItem = m_Grid.AddToGrid(ent);
        gridItem.InitContainerContext(_containerType);
    }

    void RemoveCargo(EntityAI ent)
    {
        m_Grid.RemoveFromGrid(ent);
    }

    void SetContainerType(EContainerType containerType)
    {
        _containerType = containerType;
    }

    EContainerType GetContainerType()
    {
        return _containerType;
    }

    CRDTN_UI_Grid GetGrid()
    {
        return m_Grid;
    }
};
