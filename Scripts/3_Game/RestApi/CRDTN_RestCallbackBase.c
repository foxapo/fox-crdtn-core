class CRDTN_RestCallbackBase : RestCallback
{
    ref ScriptInvoker OnSuccess = new ScriptInvoker();
    ref ScriptInvoker OnError = new ScriptInvoker();
    ref ScriptInvoker OnTimeout = new ScriptInvoker();

    override void OnError(int errorCode)
    {
        DebugUtils.Log("[RestApi]: OnError() " + errorCode.ToString());
        if(OnError)
        {
            OnError.Invoke();
        }
    }

    override void OnTimeout()
    {
        DebugUtils.Log("[RestApi]: OnTimeout()");
        if(OnTimeout)
        {
            OnTimeout.Invoke();
        }
    }

    override void OnSuccess(string data, int dataSize)
    {
        // if (dataSize > 0)
        //     DebugUtils.Log("[RestApi]: " + data);
        if (OnSuccess)
        {
            OnSuccess.Invoke(data);
        }
    }
};