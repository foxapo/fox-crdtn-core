class CRDTN_Config
{
    string CRDTN_ServerName                     = ">> SERVER NAME <<";
    string CRDTN_IntroSoundSet                  = "CRDTN_Core_SoundSet_Music_Zone";
    string CRDTN_NotificationsWrapper           = "CRDTN_Core/Layouts/Notifications/notifications.layout";
    string CRDTN_Notifications                  = "CRDTN_Core/Layouts/Notifications/notification_element.layout";
    bool   CRDTN_UseVanillaNotifications        = false;
    bool   CRDTN_DisableIntroNotification       = false;
    bool   CRDTN_Debug                          = true;
    bool   CRDTN_IntroMusic                     = true;
    ref    set<string> CRDTN_AdminList          = new ref set<string>();
    ref    map<string, string> CRDTN_Packages = new ref map<string, string>();
    
    void PrintData()
    {
        DebugUtils.Log(CRDTN_ServerName);
        DebugUtils.Log(CRDTN_IntroSoundSet);
        DebugUtils.Log(CRDTN_NotificationsWrapper);
        DebugUtils.Log(CRDTN_Notifications);
        DebugUtils.Log(CRDTN_UseVanillaNotifications.ToString());
        DebugUtils.Log(CRDTN_DisableIntroNotification.ToString());
        DebugUtils.Log(CRDTN_Debug.ToString());
        DebugUtils.Log(CRDTN_IntroMusic.ToString());
    }

    static void Save(ref CRDTN_Config dataInstance)
    {
        JsonFileLoader<ref CRDTN_Config>.JsonSaveFile(CFG_CRDTN_ConfigPath, dataInstance);
    }

    static void Load(out CRDTN_Config dataInstance)
    {
        JsonFileLoader<ref CRDTN_Config>.JsonLoadFile(CFG_CRDTN_ConfigPath, dataInstance);
        if(dataInstance.CRDTN_AdminList == null || dataInstance.CRDTN_AdminList.Count() == 0)
        {
            dataInstance.CRDTN_AdminList = new set<string>();
            dataInstance.CRDTN_AdminList.Insert("avCdzuTN2GEbHlqfPk2wXFvUyxW7CVe50bFIWgDCvN0=");
            dataInstance.CRDTN_Packages = new map<string, string>();
            dataInstance.CRDTN_Packages.Insert("COMMENT", "HERE COMES THE URLS FOR THE APIs - For example: http://localhost:9999/api");
            dataInstance.CRDTN_Packages.Insert("service-api", "endpoint");
            JsonFileLoader<ref CRDTN_Config>.JsonSaveFile(CFG_CRDTN_ConfigPath, dataInstance);
        }
    }

    string GetApi(string key)
    {
        if(!CRDTN_Packages)
        {
            return "";
        }

        if(CRDTN_Packages.Contains(key))
        {
            return CRDTN_Packages.Get(key);
        }
        return "";
    }
};