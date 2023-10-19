class CRDTN_NotificationUI : NotificationUI 
{ 
    void CRDTN_NotificationUI(string root_path) 
    { 
        m_NotificationRootPath = root_path; 
        m_Root = GetGame().GetWorkspace().CreateWidgets(m_NotificationRootPath); 
        m_Spacer = m_Root.FindAnyWidget("NotificationSpacer"); 
        m_VoiceContent = m_Root.FindAnyWidget("VoiceContent"); 
        m_NotificationContent = m_Root.FindAnyWidget("NotificationContent"); 
    } 
 
    override void AddNotification(NotificationRuntimeData data) 
    { 
        Widget notification = GetGame().GetWorkspace().CreateWidgets(m_NotificationLayoutPath, m_NotificationContent); 
        ImageWidget icon = ImageWidget.Cast(notification.FindAnyWidget("Image")); 
        RichTextWidget title = RichTextWidget.Cast(notification.FindAnyWidget("Title")); 
        if (data.GetIcon() != "") 
        { 
            icon.LoadImageFile(0, data.GetIcon()); 
            icon.Show(true); 
        }else{ 
            icon.Show(false); 
        } 
        title.SetText(data.GetTitleText()); 
        if (data.GetDetailText() != "") 
        { 
            Widget bottom_spacer = notification.FindAnyWidget("BottomSpacer"); 
            RichTextWidget detail = RichTextWidget.Cast(notification.FindAnyWidget("Detail")); 
            bottom_spacer.Show(true); 
            detail.SetText(data.GetDetailText()); 
            detail.Update(); 
            bottom_spacer.Update(); 
            notification.Update(); 
        } 
        m_Notifications.Insert(data, notification); 
        UpdateTargetHeight(); 
    } 
}; 
 
modded class NotificationUI 
{ 
    protected string m_NotificationRootPath = "gui/layouts/new_ui/notifications/notifications.layout"; 
    protected string m_NotificationLayoutPath = "gui/layouts/new_ui/notifications/notification_element.layout"; 
    void NotificationUI() {  Print(CFG_CRDTN_Core_Prefix + " NotificationUI::NotificationUI() initializing CRDTN CORE"); } 
    void SetNotificationLayout(string notificationLayout) {  m_NotificationLayoutPath = notificationLayout; } 
    void SetVanillaNotifications() {  m_NotificationLayoutPath = "gui/layouts/new_ui/notifications/notifications.layout"; } 
} 