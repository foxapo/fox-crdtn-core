// class DebugUtils
// {
//     static bool CFG_Debug = true;

//     static void Log(string message, bool overridePrint = false)
//     {
//         if (overridePrint)
//         {
//             Print(CFG_CRDTN_MAIN_PREFIX + message);
//             return;
//         }
//         if (!CFG_Debug)
//         {
//             return;
//         }
//         Print(CFG_CRDTN_MAIN_PREFIX + message);
//     }

//     static void LogTrace(string message)
//     {
//         if (!CFG_Debug)
//         {
//             return;
//         }

//         DebugPrint.LogAndTrace(CFG_CRDTN_MAIN_PREFIX + message);
//     }

//     static void LogGame(string serverName, string message)
//     {
//         Log(message);
        
//         CRDTN_RestApiWrapper api = new CRDTN_RestApiWrapper("https://localhost:7244");
//         RestApiResponse<TStringArray> requestData = new RestApiResponse<TStringArray>();
//         requestData.requestType = "_ping";
//         autoptr TStringArray data = new TStringArray;
//         #ifdef CRDTN_Sounds
//         data.Insert("CRDTN_Sounds");
//         #endif

//         #ifdef CRDTN_Gui 
//         data.Insert("CRDTN_Gui");
//         #endif

//         #ifdef CRDTN_Quests
//         data.Insert("CRDTN_Quests");
//         #endif

//         #ifdef CRDTN_Factions
//         data.Insert("CRDTN_Factions");
//         #endif

//         #ifdef CRDTN_Krabice
//         data.Insert("CRDTN_Krabice");
//         #endif

//         #ifdef CRDTN_Rad
//         data.Insert("CRDTN_Rad");
//         #endif

//         #ifdef CRDTN_QuestsServer
//         data.Insert("CRDTN_QuestsServer");
//         #endif
        
//         requestData.data = data;
//         requestData.uniqueId = serverName;
//         string json = JsonFileLoader<RestApiResponse<TStringArray>>.JsonMakeData(requestData);
//         api.ExecuteRequest("/api/ping", "POST", json);
//     }
// };