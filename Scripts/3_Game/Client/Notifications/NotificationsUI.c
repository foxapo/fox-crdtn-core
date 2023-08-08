class CRDTN_NotificationUI : NotificationUI
{
    void CRDTN_NotificationUI()
    {
        m_Root = GetGame().GetWorkspace().CreateWidgets("CRDTN_Core/Layouts/Notifications/notifications.layout");
        m_Spacer = m_Root.FindAnyWidget("NotificationSpacer");
        m_VoiceContent = m_Root.FindAnyWidget("VoiceContent");
        m_NotificationContent = m_Root.FindAnyWidget("NotificationContent");
    }

    override void AddNotification(NotificationRuntimeData data)
    {
        // This can be changed based on the settings received from the server
        Widget notification = GetGame().GetWorkspace().CreateWidgets(m_NotificationLayoutPath, m_NotificationContent);
        ImageWidget icon = ImageWidget.Cast(notification.FindAnyWidget("Image"));
        RichTextWidget title = RichTextWidget.Cast(notification.FindAnyWidget("Title"));
        if (data.GetIcon() != "")
        {
            icon.LoadImageFile(0, data.GetIcon());
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
    /// @brief Default CRDTN notification layout path
    protected string m_NotificationLayoutPath = "CRDTN_Core/Layouts/Notifications/notification_element.layout";

    void NotificationUI()
    {
        Print(CFG_CRDTN_Core_Prefix + " NotificationUI::NotificationUI() initializing CRDTN CORE");
    }

    void SetNotificationLayout(string path)
    {
        m_NotificationLayoutPath = path;
    }
}