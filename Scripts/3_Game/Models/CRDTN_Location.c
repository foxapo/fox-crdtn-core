class CRDTN_Location
{
    string Name;
    vector Coordinate;
    vector Orientation;
};

class CRDTN_NpcLocation : CRDTN_Location
{
    string ClassName;
    string NpcName;
    string GiverId;
    ref TStringArray Clothes;
    ref CRDTN_Item EquipInHands;
};