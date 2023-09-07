class CRDTN_RestApiWrapper
{
    protected string m_URL;
    protected ref CRDTN_RestCallbackBase m_Callback;
    
    protected ref CRDTN_EventHandler m_EventHandler;

    ref ScriptInvoker EOnSuccess = new ScriptInvoker();

    void CRDTN_RestApiWrapper(string url)
    {
        m_URL = url;
        m_Callback = new CRDTN_RestCallbackBase;
        m_EventHandler = new CRDTN_EventHandler;
        if (m_Callback.OnSuccess)
        {
            m_Callback.OnSuccess.Insert(OnSuccessfullRequest);
        }
    }

    ScriptInvoker AddEvent(RestApiRequestType requestType)
    {
        string requestTypeString = typename.EnumToString(RestApiRequestType, requestType);
        m_EventHandler.AddEvent(requestTypeString);
        return m_EventHandler.GetEventInvoker(requestTypeString);
    }

    // ! Used to distinguish between multiple requests of the same type
    ScriptInvoker AddEvent(RestApiRequestType requestType, string unique_id)
    {
        string requestTypeString = typename.EnumToString(RestApiRequestType, requestType);
        string identifier = requestTypeString + "_" + unique_id;
        m_EventHandler.AddEvent(identifier);
        return m_EventHandler.GetEventInvoker(identifier);
    }

    ScriptInvoker GetEvent(RestApiRequestType requestType)
    {
        string requestTypeString = typename.EnumToString(RestApiRequestType, requestType);
        return m_EventHandler.GetEventInvoker(requestTypeString);
    }

    ScriptInvoker GetEvent(RestApiRequestType requestType, string unique_id)
    {
        string requestTypeString = typename.EnumToString(RestApiRequestType, requestType);
        string identifier = requestTypeString + "_" + unique_id;
        return m_EventHandler.GetEventInvoker(identifier);
    }

    void RemoveEvent(RestApiRequestType requestType, string unique_id)
    {
        string requestTypeString = typename.EnumToString(RestApiRequestType, requestType);
        string identifier = requestTypeString + "_" + unique_id;
        m_EventHandler.RemoveEvent(identifier);
    }

    void ExecuteRequest(string url, string method, string data)
    {        
        DebugUtils.Log("[CRDTN_RestApiWrapper]: ExecuteRequest() - " + url + " " + method + " " + data);
        RestContext ctx = GetGame().GetRestApi().GetRestContext(m_URL);
        ctx.SetHeader("application/json");
        switch(method)
        {
            case "GET":
                ctx.GET(m_Callback, url);
                break;
            case "POST":
                ctx.POST(m_Callback, url, data);
                break;
        }
    }

    void OnSuccessfullRequest(string response)
    {
        if (!response)
        {
            DebugUtils.Log("[CRDTN_RestApiWrapper]: OnSuccessfullRequest() - response is null");
            return;
        }
        // DebugUtils.Log("[CRDTN_RestApiWrapper]: OnSuccessfullRequest() - " + response);
        string unique_id = "";
        RestApiRequestType requestType = CRDTN_GlobalUtils.GetRequestType(response, unique_id);
        ScriptInvoker invoker;

        if(unique_id != "")
        {
            invoker = GetEvent(requestType, unique_id);
        }
        else
        {
            invoker = GetEvent(requestType);
        }

        if (invoker)
        {
            invoker.Invoke(response);
        }
    }
}