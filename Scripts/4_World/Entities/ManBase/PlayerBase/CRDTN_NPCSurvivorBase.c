class CRDTN_NPCSurvivorBase extends SurvivorBase
{
    protected string m_Name = "";
    protected string m_ActionText = "";

    void CRDTN_NPCSurvivorBase()
    {
        // Disable damage
        SetAllowDamage(false);
    }

    override void SetActions()
    {
        super.SetActions();
        RemoveAction(ActionCheckPulse);
        RemoveAction(ActionCheckPulseTarget);
        if(m_IsQuestGiver && !IsPlayer())
        {
            AddAction(ActionOpenQuests);
        }
    }

    override string GetDisplayName()
    {
        return m_Name;
    }

    string GetActionText()
    {
        return m_ActionText;
    }

    void EquipInHands(string classname)
    {
        Man man = Man.Cast(this);
        man.GetHumanInventory().CreateInHands(classname);
    }

    void EquipCRDTN_Item(CRDTN_Item item)
    {
        Man man = Man.Cast(this);
        EntityAI ent = EntityAI.Cast(man.GetHumanInventory().CreateInHands(item.ClassName));
        if(ent && ent.GetInventory())
        {
            foreach(CRDTN_Item attachment : item.Attachments)
            {
                ent.GetInventory().CreateAttachment(attachment.ClassName);
            }
        }
    }

    override void EEInit()
    {
        super.EEInit();
        if(IsPlayer())
        {
            return;
        }
        CRDTN_NPCInit();
    }

    void CRDTN_NPCInit();
};

class CRDTN_SurvivorM_Mirek : CRDTN_NPCSurvivorBase
{
    // Mirek
    void CRDTN_SurvivorM_Mirek()
    {
        m_Name = "Mirek";
    }
};
class CRDTN_SurvivorM_Boris : CRDTN_NPCSurvivorBase
{
    // Boris
    void CRDTN_SurvivorM_Boris()
    {
        m_Name = "Boris";
    }
};
class CRDTN_SurvivorM_Cyril : CRDTN_NPCSurvivorBase
{
    // Cyril
    void CRDTN_SurvivorM_Cyril()
    {
        m_Name = "Cyril";
    }
};
class CRDTN_SurvivorM_Denis : CRDTN_NPCSurvivorBase
{
    // Denis
    void CRDTN_SurvivorM_Denis()
    {
        m_Name = "Denis";
    }
};
class CRDTN_SurvivorM_Elias : CRDTN_NPCSurvivorBase
{
    // Elias
    void CRDTN_SurvivorM_Elias()
    {
        m_Name = "Elias";
    }
};
class CRDTN_SurvivorM_Francis : CRDTN_NPCSurvivorBase
{
    // Francis
    void CRDTN_SurvivorM_Francis()
    {
        m_Name = "Francis";
    }
};
class CRDTN_SurvivorM_Guo : CRDTN_NPCSurvivorBase
{
    // Guo
    void CRDTN_SurvivorM_Guo()
    {
        m_Name = "Guo";
    }
};
class CRDTN_SurvivorM_Hassan : CRDTN_NPCSurvivorBase
{
    // Hassan
    void CRDTN_SurvivorM_Hassan()
    {
        m_Name = "Hassan";
    }
};
class CRDTN_SurvivorM_Indar : CRDTN_NPCSurvivorBase
{
    // Indar
    void CRDTN_SurvivorM_Indar()
    {
        m_Name = "Indar";
    }
};
class CRDTN_SurvivorM_Jose : CRDTN_NPCSurvivorBase
{
    // Jose
    void CRDTN_SurvivorM_Jose()
    {
        m_Name = "Jose";
    }
};
class CRDTN_SurvivorM_Kaito : CRDTN_NPCSurvivorBase
{
    // Kaito
    void CRDTN_SurvivorM_Kaito()
    {
        m_Name = "Kaito";
    }
};
class CRDTN_SurvivorM_Lewis : CRDTN_NPCSurvivorBase
{
    // Lewis
    void CRDTN_SurvivorM_Lewis()
    {
        m_Name = "Lewis";
    }
};
class CRDTN_SurvivorM_Manua : CRDTN_NPCSurvivorBase
{
    // Manua
    void CRDTN_SurvivorM_Manua()
    {
        m_Name = "Manua";
    }
};
class CRDTN_SurvivorM_Niki : CRDTN_NPCSurvivorBase
{
    // Niki
    void CRDTN_SurvivorM_Niki()
    {
        m_Name = "Niki";
    }
};
class CRDTN_SurvivorM_Oliver : CRDTN_NPCSurvivorBase
{
    // Oliver
    void CRDTN_SurvivorM_Oliver()
    {
        m_Name = "Oliver";
    }
};
class CRDTN_SurvivorM_Peter : CRDTN_NPCSurvivorBase
{
    // Peter
    void CRDTN_SurvivorM_Peter()
    {
        m_Name = "Peter";
    }
};
class CRDTN_SurvivorM_Quinn : CRDTN_NPCSurvivorBase
{
    // Quinn
    void CRDTN_SurvivorM_Quinn()
    {
        m_Name = "Quinn";
    }
};
class CRDTN_SurvivorM_Rolf : CRDTN_NPCSurvivorBase
{
    // Rolf
    void CRDTN_SurvivorM_Rolf()
    {
        m_Name = "Rolf";
    }
};
class CRDTN_SurvivorM_Seth : CRDTN_NPCSurvivorBase
{
    // Seth
    void CRDTN_SurvivorM_Seth()
    {
        m_Name = "Seth";
    }
};
class CRDTN_SurvivorM_Taiki : CRDTN_NPCSurvivorBase
{
    // Taiki
    void CRDTN_SurvivorM_Taiki()
    {
        m_Name = "Taiki";
    }
};
class CRDTN_SurvivorF_Eva : CRDTN_NPCSurvivorBase
{
    // Eva
    void CRDTN_SurvivorF_Eva()
    {
        m_Name = "Eva";
    }
};
class CRDTN_SurvivorF_Frida : CRDTN_NPCSurvivorBase
{
    // Frida
    void CRDTN_SurvivorF_Frida()
    {
        m_Name = "Frida";
    }
};
class CRDTN_SurvivorF_Gabi : CRDTN_NPCSurvivorBase
{
    // Gabi
    void CRDTN_SurvivorF_Gabi()
    {
        m_Name = "Gabi";
    }
};
class CRDTN_SurvivorF_Helga : CRDTN_NPCSurvivorBase
{
    // Helga
    void CRDTN_SurvivorF_Helga()
    {
        m_Name = "Helga";
    }
};
class CRDTN_SurvivorF_Irena : CRDTN_NPCSurvivorBase
{
    // Irena
    void CRDTN_SurvivorF_Irena()
    {
        m_Name = "Irena";
    }
};
class CRDTN_SurvivorF_Judy : CRDTN_NPCSurvivorBase
{
    // Judy
    void CRDTN_SurvivorF_Judy()
    {
        m_Name = "Judy";
    }
};
class CRDTN_SurvivorF_Keiko : CRDTN_NPCSurvivorBase
{
    // Keiko
    void CRDTN_SurvivorF_Keiko()
    {
        m_Name = "Keiko";
    }
};
class CRDTN_SurvivorF_Linda : CRDTN_NPCSurvivorBase
{
    // Linda
    void CRDTN_SurvivorF_Linda()
    {
        m_Name = "Linda";
    }
};
class CRDTN_SurvivorF_Maria : CRDTN_NPCSurvivorBase
{
    // Maria
    void CRDTN_SurvivorF_Maria()
    {
        m_Name = "Maria";
    }
};
class CRDTN_SurvivorF_Naomi : CRDTN_NPCSurvivorBase
{
    // Naomi
    void CRDTN_SurvivorF_Naomi()
    {
        m_Name = "Naomi";
    }
};
class CRDTN_SurvivorF_Baty : CRDTN_NPCSurvivorBase
{
    // Baty
    void CRDTN_SurvivorF_Baty()
    {
        m_Name = "Baty";
    }
};