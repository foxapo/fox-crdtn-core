class CRDTN_EventHandler
{
    private ref map<string, ref ScriptInvoker> events;

	void CRDTN_EventHandler()
	{
		events = new map<string, ref ScriptInvoker>;
		AddEvent(CRDTN_EVT_PLAYER_FACTION_SYNC);
	}
	void AddEvent(string eventName)
	{
		if(events.Contains(eventName))
		{
			Print("[" + ClassName() + "]:: Duplicate Event Added: " + eventName);
			return;
		}
		if(!events.Contains(eventName))
			events.Insert(eventName, new ScriptInvoker());
	}
	ScriptInvoker GetEventInvoker(string eventName)
	{
		ScriptInvoker eventInvoker;
		if(!events.Contains(eventName))
		{
			Print("[" + ClassName() + "]:: Invalid Event: " + eventName);
			return null;
		}
		if(events.Contains(eventName))
		{
			eventInvoker = events[eventName];
		}
		return eventInvoker;
	}
};