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
			return;
		}
		if(!events.Contains(eventName))
		{
			events.Insert(eventName, new ScriptInvoker());
		}
	}

	ScriptInvoker GetEventInvoker(string eventName)
	{
		ScriptInvoker eventInvoker;
		if(!events.Contains(eventName))
		{
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
			return;
		}
		
		if(events.Contains(eventName))
		{
			events.Remove(eventName);
		}
	}

	void RegisterEvent(string invoker, func callback)
	{
		if(!events.Contains(invoker))
		{
			AddEvent(invoker);
		}
		
		if(events.Contains(invoker))
		{
			events[invoker].Insert(callback);
		}
	}

	void UnregisterEvent(string invoker, func callback)
	{
		if(!events.Contains(invoker))
		{
			return;
		}
		if(events.Contains(invoker))
		{
			events[invoker].Remove(callback);
		}
	}
};