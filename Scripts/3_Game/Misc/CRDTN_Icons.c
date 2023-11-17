
enum CRDTN_IconType
{
    _NONE,
    Map,
    Water,
    Energy,
    Radioactive,
    Tent,
    Crafting,
    Lighter,
    GoalActive,
    GoalComplete
};

class CRDTN_Icons
{
    static string GetIcon(CRDTN_IconType type)
    {
        switch (type)
        {
            case CRDTN_IconType.Map:
                return "CRDTN_Core/data/images/icons/29.edds";
            case CRDTN_IconType.Water:
                return "CRDTN_Core/data/images/icons/31.edds";
            case CRDTN_IconType.Energy:
                return "CRDTN_Core/data/images/icons/32.edds";
            case CRDTN_IconType.Radioactive:
                return "CRDTN_Core/data/images/icons/43.edds";
            case CRDTN_IconType.Tent:
                return "CRDTN_Core/data/images/icons/44.edds";
            case CRDTN_IconType.Crafting:
                return "CRDTN_Core/data/images/icons/82.edds";
            case CRDTN_IconType.Lighter:
                return "CRDTN_Core/data/images/icons/83.edds";
            case CRDTN_IconType.GoalActive:
                return "CRDTN_Quests/data/images/icons/21.edds";
            case CRDTN_IconType.GoalComplete:
                return "CRDTN_Quests/data/images/icons/59.edds";
            default:
                return "";
        }

        return "";
    }

    static string GetIconById(string id)
    {
        return "CRDTN_Core/data/images/icons/" + id + ".edds";
    }
};