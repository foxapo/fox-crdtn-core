modded class PluginManager
{
	override void Init()
	{
		super.Init();
		if(GetGame().IsClient())
        	RegisterPlugin("CRDTN_CorePluginClient", true, false);
		if(GetGame().IsServer() && !GetGame().IsClient())
        	RegisterPlugin("CRDTN_CorePluginServer", false, true);
	}
}