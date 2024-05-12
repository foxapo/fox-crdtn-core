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

enum EContainerType
{
    TRADER_STOCK,
    TRADER_BUY,
    TRADER_SELL,
    TRADER_PLAYER
};