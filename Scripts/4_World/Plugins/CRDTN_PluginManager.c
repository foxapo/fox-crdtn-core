modded class PluginManager
{
	override void Init()
	{
		super.Init();
        RegisterPlugin("CRDTN_CorePlugin", true, true);
	}
}