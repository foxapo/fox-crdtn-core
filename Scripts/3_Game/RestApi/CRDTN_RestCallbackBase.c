class CRDTN_RestCallbackBase : RestCallback
{
    ref ScriptInvoker OnSuccess = new ScriptInvoker();
    ref ScriptInvoker OnError = new ScriptInvoker();
    ref ScriptInvoker OnTimeout = new ScriptInvoker();

    override void OnError(int errorCode)
    {
        DebugUtils.Log("[CRDTN_RestApiWrapper]: OnError()" + errorCode.ToString());
        if (OnError)
        {
            OnError.Invoke();
        }
    }

    override void OnTimeout()
    {
        DebugUtils.Log("[CRDTN_RestApiWrapper]: OnTimeout()");
        if (OnTimeout)
        {
            OnTimeout.Invoke();
        }
    }

    override void OnSuccess(string data, int dataSize)
    {
        if (OnSuccess)
        {
            OnSuccess.Invoke(data);
        }
    }
};