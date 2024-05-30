  /**
 * @brief Enumeration of different types of REST API requests.
 */
enum RestApiRequestType
{
  GET_ALL_CATEGORIES            ,  // KRABICE 
  GET_ALL_ZONES                 ,  // KRABICE 
  GET_ALL_LOCATIONS             ,  // KRABICE 
  GET_ALL_STATIC                ,  // KRABICE 
  GET_ALL_STATIC_WITH_CATEGORIES,  // KRABICE 
  GET_ALL_STATIC_WITH_ZONES     ,  // KRABICE 
  GET_LOOT_BY_NAME              ,  // KRABICE
  GET_LOOT_BY_CATEGORY          ,  // KRABICE
  GET_LOOT_BY_ZONE              ,  // KRABICE
  AUTH_TEST                     ,  // AUTH
  GET_TRADER                    ,  // TRADING 
  GET_STOCK                     ,  // TRADING 
  GET_PRODUCT                   ,  // TRADING 
  BUY_PRODUCT                   ,  // TRADING 
  SELL_PRODUCT                  ,  // TRADING
  GET_PLAYER_DATA               ,  // WORLD
  GET_ALL_SPAWNS                ,  // SPAWNS
  GET_ALL_RAD_ZONES             ,  // RADIATION
  IS_IN_RAD_ZONE                ,  // RADIATION
  GET_ALL_RAD_ZONES_COUNT       ,  // RADIATION
  METRICS_LOOTED_ITEMS_ALL      ,  // METRICS
  GET_ALL_TRADER_PRICES         ,  // TRADING
  PENDING_PRODUCT_CREATION      ,  // TRADING
  ITEM_BASE_CREATE              ,  // ITEM_BASE
  ITEM_BASE_UPDATE              ,  // ITEM_BASE
  ITEM_BASE_DELETE              ,  // ITEM_BASE
  ITEM_BASE_GET                 ,  // ITEM_BASE
  ITEM_BASE_GET_ALL                // ITEM_BASE
};
