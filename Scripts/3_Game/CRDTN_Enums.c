// ! DO NOT GET CONFUSED BY THIS, IT IS USED ACROSS MULTIPLE MODS WHICH ARE NOT EVEN PUBLIC ! // 
// ! DO NOT REWRITE THIS FILE - ONLY ADD NEW VALUES AT THE END ! //

/// @brief Used for in the combat to determine which kind of combat situation happened
enum CRDTN_ECombatEvent
{
    _NONE,
    PSI_HIT,
    PSI_EXPLOSION,
    PSI_KILLED,
    _COUNT
};

enum CRDTN_EEffectAreaType
{
    PSI
};

enum CRDTN_ETriggerType
{
    PSI
};

enum CRDTN_ECurrencyType
{
    _NONE,
    CZECH_CROWNS,
    EURO
};

enum CRDTN_EMenuContext
{
    _NONE,
    PLAYER
};

enum CRDTN_RPC_NPC
{
    _NONE,
    SYNC_NPC,
    SYNC_NPC_INFO,
};

enum CRDTN_DataFeedType
{
    _NONE,
    DEFAULT,
    WORKBENCH,
};

/// @brief Extend the contaienr type if you need more contexts, for example quests, workbench 
/// Use this to distinguish the visual appearance of the CRDTN_UI_GridItem::InitContainerContext 
enum EContainerType
{
    TRADER_STOCK,
    TRADER_BUY,
    TRADER_SELL,
    TRADER_PLAYER
};