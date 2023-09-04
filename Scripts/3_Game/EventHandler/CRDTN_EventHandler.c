class CRDTN_EventHandler
{
    private ref map<string, ref ScriptInvoker> events;

	void CRDTN_EventHandler()
	{
		events = new map<string, ref ScriptInvoker>;
	}

	void AddEvent(string eventName)
	{
		if(events.Contains(eventName))
		{
			DebugUtils.Log(CFG_CRDTN_Core_Prefix + " CRDTN_EventHandler :: Event already exists: " + eventName);
			return;
		}
		if(!events.Contains(eventName))
		{
			DebugUtils.Log(CFG_CRDTN_Core_Prefix + " CRDTN_EventHandler :: AddEvent() - " + eventName);
			events.Insert(eventName, new ScriptInvoker());
		}
	}

	ScriptInvoker GetEventInvoker(string eventName)
	{
		ScriptInvoker eventInvoker;
		if(!events.Contains(eventName))
		{
			DebugUtils.Log(CFG_CRDTN_Core_Prefix + " CRDTN_EventHandler :: Invalid Event: " + eventName);
			return null;
		}
		if(events.Contains(eventName))
		{
			eventInvoker = events[eventName];
		}
		return eventInvoker;
	}

	void RemoveEvent(string eventName)
	{
		if(!events.Contains(eventName))
		{
			DebugUtils.Log(CFG_CRDTN_Core_Prefix + " CRDTN_EventHandler :: Invalid Event: " + eventName);
			return;
		}
		
		if(events.Contains(eventName))
		{
			DebugUtils.Log(CFG_CRDTN_Core_Prefix + " CRDTN_EventHandler :: RemoveEvent() - " + eventName);
			events.Remove(eventName);
		}
	}
};