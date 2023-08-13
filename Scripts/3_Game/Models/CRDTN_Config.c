class CRDTN_Config
{
    string CRDTN_ServerName               = "<< CRDTN Server | PVP/PVE | 1PP >>";
    string CRDTN_IntroSoundSet            = "CRDTN_Core_SoundSet_Music_Zone";
    string CRDTN_NotificationsWrapper     = "CRDTN_Core/Layouts/Notifications/notifications.layout";
    string CRDTN_Notifications            = "CRDTN_Core/Layouts/Notifications/notification_element.layout";
    bool   CRDTN_UseVanillaNotifications  = false;
    bool   CRDTN_DisableIntroNotification = false;
    bool   CRDTN_Debug                    = true;
    bool   CRDTN_IntroMusic               = true;
    
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
    }
};