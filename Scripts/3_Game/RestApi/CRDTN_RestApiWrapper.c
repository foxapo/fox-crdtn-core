  /**
 * This file contains the implementation of the CRDTN_RestApiWrapper class, which is responsible for handling REST API requests.
 */

  /**
 * This function calculates the sum of two integers.
 *
 * @param a The first integer.
 * @param b The second integer.
 * @return The sum of the two integers.
 */
int calculateSum(int a, int b) {
    return a + b;
}

  /**
 * The CRDTN_RestApiWrapper class is responsible for handling REST API requests.
 */
class CRDTN_RestApiWrapper
{
    protected string m_URL;
    protected ref CRDTN_RestCallbackBase m_Callback;
    protected ref CRDTN_EventHandler m_EventHandler;
    ref ScriptInvoker EOnSuccess = new ScriptInvoker();

      /**
     * Constructs a new instance of the CRDTN_RestApiWrapper class.
     *
     * @param url The URL of the REST API.
     */
    void CRDTN_RestApiWrapper(string url)
    {
        m_URL = url;
        GetRestApi().EnableDebug(true);
        m_Callback     = new CRDTN_RestCallbackBase;
        m_EventHandler = new CRDTN_EventHandler;
        if (m_Callback.OnSuccess)
        {
            m_Callback.OnSuccess.Insert(OnSuccessfullRequest);
        }
    }

      /**
     * Adds an event for the specified REST API request type.
     *
     * @param requestType The REST API request type.
     * @return The event invoker for the added event.
     */
    ScriptInvoker AddEvent(RestApiRequestType requestType)
    {
        string requestTypeString = typename.EnumToString(RestApiRequestType, requestType);
        m_EventHandler.AddEvent(requestTypeString);
        return m_EventHandler.GetEventInvoker(requestTypeString);
    }

      /**
     * Adds an event for the specified REST API request type and unique ID.
     *
     * @param requestType The REST API request type.
     * @param unique_id The unique ID.
     * @return The event invoker for the added event.
     */
    ScriptInvoker AddEvent(RestApiRequestType requestType, string unique_id)
    {
        string requestTypeString = typename.EnumToString(RestApiRequestType, requestType);
        string identifier        = requestTypeString + "_" + unique_id;
        m_EventHandler.AddEvent(identifier);
        return m_EventHandler.GetEventInvoker(identifier);
    }

      /**
     * Gets the event invoker for the specified REST API request type.
     *
     * @param requestType The REST API request type.
     * @return The event invoker for the specified REST API request type.
     */
    ScriptInvoker GetEvent(RestApiRequestType requestType)
    {
        string requestTypeString = typename.EnumToString(RestApiRequestType, requestType);
        return m_EventHandler.GetEventInvoker(requestTypeString);
    }

      /**
     * Gets the event invoker for the specified REST API request type and unique ID.
     *
     * @param requestType The REST API request type.
     * @param unique_id The unique ID.
     * @return The event invoker for the specified REST API request type and unique ID.
     */
    ScriptInvoker GetEvent(RestApiRequestType requestType, string unique_id)
    {
        string requestTypeString = typename.EnumToString(RestApiRequestType, requestType);
        string identifier        = requestTypeString + "_" + unique_id;
        return m_EventHandler.GetEventInvoker(identifier);
    }

      /**
     * Removes the event for the specified REST API request type and unique ID.
     *
     * @param requestType The REST API request type.
     * @param unique_id The unique ID.
     */
    void RemoveEvent(RestApiRequestType requestType, string unique_id)
    {
        string requestTypeString = typename.EnumToString(RestApiRequestType, requestType);
        string identifier        = requestTypeString + "_" + unique_id;
        m_EventHandler.RemoveEvent(identifier);
    }

      /**
     * Executes a REST API request.
     *
     * @param url The URL of the request.
     * @param method The HTTP method of the request.
     * @param data The data to send with the request.
     */
    void ExecuteRequest(string url, string method, string data)
    {        
        RestContext ctx = GetRestApi().GetRestContext(m_URL);
        ctx.SetHeader("application/json");
        switch(method)
        {
            case "GET": 
                ctx.GET(m_Callback, url);
                  // DebugUtils.Log("[CRDTN_RestApiWrapper]: ExecuteRequest() - GET " + url);
                break;
            case "POST": 
                ctx.POST(m_Callback, url, data);
                  // DebugUtils.Log("[CRDTN_RestApiWrapper]: ExecuteRequest() - POST " + url);
                break;
        }
    }

      /**
     * Handles the successful response of a REST API request.
     *
     * @param response The response data.
     */
    void OnSuccessfullRequest(string response)
    {
        if (!response)
        {
            DebugUtils.Log("[CRDTN_RestApiWrapper]: OnSuccessfullRequest() - response is null");
            return;
        }
          // DebugUtils.Log("[CRDTN_RestApiWrapper]: OnSuccessfullRequest() - " + response);
        string             unique_id   = "";
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