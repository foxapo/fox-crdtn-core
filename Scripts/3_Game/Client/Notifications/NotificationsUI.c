class CRDTN_NotificationUI : NotificationUI
{
   
    void CRDTN_NotificationUI()
    {
        DebugPrint.LogAndTrace(CFG_CRDTN_Core_Prefix + " CRDTN_NotificationUI::CRDTN_NotificationUI() initializing CRDTN CORE");
        m_Root = GetGame().GetWorkspace().CreateWidgets("CRDTN_Core/Layouts/Notifications/notifications.layout");
        m_Spacer = m_Root.FindAnyWidget("NotificationSpacer");
        m_VoiceContent = m_Root.FindAnyWidget("VoiceContent");
        m_NotificationContent = m_Root.FindAnyWidget("NotificationContent");
    }

    override void AddNotification(NotificationRuntimeData data)
    {
        DebugPrint.LogAndTrace(CFG_CRDTN_Core_Prefix + " CRDTN_NotificationUI::AddNotification() initializing CRDTN CORE");
        Widget notification = GetGame().GetWorkspace().CreateWidgets("CRDTN_Core/Layouts/Notifications/notification_element.layout", m_NotificationContent);

        ImageWidget icon = ImageWidget.Cast(notification.FindAnyWidget("Image"));
        RichTextWidget title = RichTextWidget.Cast(notification.FindAnyWidget("Title"));

        if (data.GetIcon() != "")
            icon.LoadImageFile(0, data.GetIcon());
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
    void NotificationUI()
    {
        Print(CFG_CRDTN_Core_Prefix + " NotificationUI::NotificationUI() initializing CRDTN CORE");
    }
}