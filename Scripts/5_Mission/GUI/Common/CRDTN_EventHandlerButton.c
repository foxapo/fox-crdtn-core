class CRDTN_EventHandlerButton extends ScriptedWidgetEventHandler
{
    protected Widget m_Root;
    private ButtonWidget m_ButtonWidget;
  
    private ref ScriptInvoker m_EventInvoker;
    private ref Param m_ContextData;

    private string ButtonDownEvent  = "";
    private string ButtonEnterEvent = "";
    private string ButtonLeaveEvent = "";

    ref ScriptInvoker EMouseEnter;
    ref ScriptInvoker EMouseLeave;
    ref ScriptInvoker EClick     ;


    void OnWidgetScriptInit(Widget w)
    {
        m_Root         = w;
        m_ButtonWidget = ButtonWidget.Cast(m_Root.FindAnyWidget("CRDTN_EventHandlerButton"));
        w.SetHandler(this);
    }

    void InitButton()
    {
        EMouseEnter = new ScriptInvoker();
        EMouseLeave = new ScriptInvoker();
        EClick      = new ScriptInvoker();
    }

    void SetEventData(ref Param data)
    {
        m_ContextData = data;
    }

    void SetEventInvoker(ref ScriptInvoker eventInvoker)
    {
        m_EventInvoker = eventInvoker;
    }


    override bool OnMouseButtonDown(Widget w, int x, int y, int button)
    {
        if (w == m_ButtonWidget)
        {
           if(m_EventInvoker)
           {
                m_EventInvoker.Invoke(ButtonDownEvent, m_ContextData);
           }

           if(EClick)
           {
                EClick.Invoke();
           }

            return true;
        }
        return false;
    }

    override bool OnMouseEnter(Widget w, int x, int y)
    {
        if (w == m_ButtonWidget)
        {
            if(m_EventInvoker)
            {
                m_EventInvoker.Invoke(ButtonEnterEvent, m_ContextData);
            }

            if(EMouseEnter)
            {
                EMouseEnter.Invoke();
            }

            return true;
        }
        return false;
    }

    override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
    {
        if (w == m_ButtonWidget)
        {
            if(m_EventInvoker)
            {
                m_EventInvoker.Invoke(ButtonLeaveEvent, m_ContextData);
            }

            if(EMouseLeave)
            {
                EMouseLeave.Invoke();
            }

            return true;
        }
        return false;
    }

};