class CRDTN_Item
{
    string ClassName;
    string Slot;
    ref array<ref CRDTN_Item> Attachments;

    void CRDTN_Item(string className, string slot = "")
    {
        ClassName = className;
        Slot = slot;
        Attachments = new array<ref CRDTN_Item>();
    }

    void AddAttachments(TStringArray attachments)
    {
        if(attachments == NULL)
        {
            return;
        }
        foreach(string attachment : attachments)
        {
            Attachments.Insert(new CRDTN_Item(attachment));
        }
    }
};