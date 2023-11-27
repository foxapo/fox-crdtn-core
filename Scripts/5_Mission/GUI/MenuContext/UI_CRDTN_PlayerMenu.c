// CFG_CRDTN_UI_Menu_ListEntry
// CFG_CRDTN_UI_Menu_Category
// CFG_CRDTN_UI_Menu_Element_Divider
// CFG_CRDTN_UI_Menu_Element_Header
// CFG_CRDTN_UI_Menu_Element_ItemPreview
// CFG_CRDTN_UI_Menu_Element_Text

class CRDTN_PlayerMenu : UI_CRDTNMenu
{

    ref MultilineTextWidget m_BodyHeader;
    ref MultilineTextWidget m_BodyText;

    Param2<string, string> GetMockDataBaseBuilding()
    {
        return new Param2<string, string>("Base Building", "Base building is the process of constructing and fortifying a shelter or base to protect yourself from the dangers of DayZ. You can build walls, fences, gates, watchtowers, and more to create a secure and customized safe haven. Base building often involves gathering resources and planning your base's layout strategically.");
    }

    Param2<string, string> GetMockDataCrafting()
    {
        return new Param2<string, string>("Crafting", "You can craft items like weapons, clothing, and tools to help you survive and thrive in the post-apocalyptic environment. To craft, you'll need the right materials and access to crafting stations like workbenches.");
    }

    Param2<string, string> GetMockDataFood()
    {
        return new Param2<string, string>("Food", "Food is essential for your character's survival in DayZ. You must scavenge for various types of food, such as canned goods, fruits, vegetables, and meat. Consuming food replenishes your energy and hydration levels. Be cautious of food spoilage and foodborne illnesses, as they can affect your character's health.");
    }

    Param2<string, string> GetMockDataWater()
    {
        return new Param2<string, string>("Water", "Staying hydrated is crucial in DayZ. You need to find sources of clean water, such as wells, ponds, or bottles of water, to quench your character's thirst. Drinking contaminated water or neglecting hydration can lead to negative status effects and even death, so managing your water supply is vital.");
    }

    Param2<string, string> GetMockDataRadiation()
    {
        return new Param2<string, string>("Radiation", "Radiation is a hazard in certain areas of the DayZ map, particularly around military installations and nuclear facilities. Exposure to radiation can result in radiation sickness, which affects your character's health and can lead to death if not treated. To protect yourself from radiation, wear protective gear like gas masks and use Geiger counters to monitor radiation levels in the environment.");
    }

    override void InitMain(CRDTN_EMenuContext context)
    {
        string playerName = GetGame().GetPlayer().GetIdentity().GetName();
        m_ContextHeaderText.SetText(playerName);
    }

    override void InitNavigation(CRDTN_EMenuContext context)
    {
        autoptr GridSpacerWidget categoryStats = AddNavigationCategory( m_NavigationGrid, "Stats");
        autoptr UI_CRDTNListEntry crafting = AddListEntry(categoryStats, "Crafting", "RULES", CRDTN_Icons.GetIcon(CRDTN_IconType.Crafting));
        autoptr UI_CRDTNListEntry base = AddListEntry(categoryStats, "Base Building", "RULES", CRDTN_Icons.GetIcon(CRDTN_IconType.Tent));
        autoptr UI_CRDTNListEntry rad = AddListEntry(categoryStats, "Radiation", "RULES", CRDTN_Icons.GetIcon(CRDTN_IconType.Radioactive));
        autoptr GridSpacerWidget categoryLocations = AddNavigationCategory(m_NavigationGrid, "Travel");
        autoptr UI_CRDTNListEntry vorkuta = AddListEntry(categoryLocations, "Vorkuta", "POINT OF INTEREST", CRDTN_Icons.GetIcon(CRDTN_IconType.Map));
        autoptr UI_CRDTNListEntry dam = AddListEntry(categoryLocations, "Sebjan Dam", "POINT OF INTEREST", CRDTN_Icons.GetIcon(CRDTN_IconType.Map));
        crafting.ContextData = GetMockDataCrafting();
        base.ContextData = GetMockDataBaseBuilding();
        rad.ContextData = GetMockDataRadiation();
        vorkuta.ContextData = GetMockDataFood();
        dam.ContextData = GetMockDataWater();
    }

    override void InitContent(CRDTN_EMenuContext context)
    {
    }

    override void InitEntryData(ref Param data)
    {
        Param2<string, string> data2 = Param2<string, string>.Cast(data);
        AddBodyHeader(data2.param1);
        AddDivider();
        AddBodyText(data2.param2);
    }
};