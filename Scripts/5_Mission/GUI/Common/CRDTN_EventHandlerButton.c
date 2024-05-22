class CRDTN_EventHandlerButton extends ScriptedWidgetEventHandler
{
    protected Widget m_Root;

    private ButtonWidget m_ButtonWidget;
    private ref Param m_ContextData;

    private ref CRDTN_EventHandler m_EventHandler;
    private string m_ButtonDownEvent  = "";
    private string m_ButtonEnterEvent = "";
    private string m_ButtonLeaveEvent = "";

    private ref ScriptInvoker EMouseClick;
    private ref ScriptInvoker EMouseEnter;
    private ref ScriptInvoker EMouseLeave;

    void OnWidgetScriptInit(Widget w)
    {
        m_Root         = w;
        m_ButtonWidget = ButtonWidget.Cast(m_Root.FindAnyWidget("CRDTN_EventHandlerButton"));
        w.SetHandler(this);
    }

    void SetEventInvokers(ref ScriptInvoker mouseClick, ref ScriptInvoker mouseEnter, ref ScriptInvoker mouseLeave)
    {
        EMouseClick = mouseClick;
        EMouseEnter = mouseEnter;
        EMouseLeave = mouseLeave;
    }

    void SetEventNames(ref CRDTN_EventHandler eventHandler, string buttonDownEvent = "", string buttonEnterEvent = "", string buttonLeaveEvent = "")
    {
        m_EventHandler     = eventHandler;
        m_ButtonDownEvent  = buttonDownEvent;
        m_ButtonEnterEvent = buttonEnterEvent;
        m_ButtonLeaveEvent = buttonLeaveEvent;
    }

    void ~CRDTN_EventHandlerButton()
    {
        m_ButtonWidget = NULL;
        m_ContextData = NULL;
        m_EventHandler = NULL;
        EMouseClick = NULL;
        EMouseEnter = NULL;
        EMouseLeave = NULL;
        // m_Root.Unlink();
    }

    void SetEventData(ref Param data)
    {
        m_ContextData = data;
    }

    override bool OnMouseButtonDown(Widget w, int x, int y, int button)
    {
        if (w != m_ButtonWidget)
        {
            return false;
        }


        EMouseClick.Invoke(m_ContextData);	
       

        if(m_ButtonDownEvent != "" && m_EventHandler)
        {
            m_EventHandler.GetEventInvoker(m_ButtonDownEvent).Invoke(m_ContextData);
        }

        return true;
    }

    override bool OnMouseEnter(Widget w, int x, int y)
    {
        if (w != m_ButtonWidget || (m_ButtonEnterEvent == "" && !EMouseEnter))
        {
            return false;
        }
       
        if (EMouseEnter)
        {
            EMouseEnter.Invoke(x, y);
        }

        if(m_ButtonEnterEvent != "" && m_EventHandler)
        {
            m_EventHandler.GetEventInvoker(m_ButtonEnterEvent).Invoke(m_ContextData);
        }
      
        return true;
    }

    override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
    {
        if (w != m_ButtonWidget || (m_ButtonLeaveEvent == "" && !EMouseLeave))
        {
            return false;
        }

        if (EMouseLeave)
        {
            EMouseLeave.Invoke(x, y);
        }

        if(m_ButtonLeaveEvent != "" && m_EventHandler)
        {
            m_EventHandler.GetEventInvoker(m_ButtonLeaveEvent).Invoke(m_ContextData);
        }

        return true;
      
    }
};