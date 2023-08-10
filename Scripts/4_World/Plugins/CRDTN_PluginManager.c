modded class PluginManager
{
	override void Init()
	{
		if(GetGame().IsClient())
        	RegisterPlugin("CRDTN_CorePluginClient", true, false);
		if(GetGame().IsDedicatedServer())
        	RegisterPlugin("CRDTN_CorePluginServer", false, true);
		super.Init();
	}
}