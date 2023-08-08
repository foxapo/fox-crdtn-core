class CRDTN_CorePluginClient : CRDTN_CorePluginBase
{
    void RPC_ServerConfigReceived(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {
        if (type != CallType.Client)
            return;

        Param1<ref CRDTN_Config> data;
        if (!ctx.Read(data))
        {
            return;
        }

        m_Config = data.param1;
        if (m_Config == null)
        {
            return;
        }
        g_Game.SetCRDTNCoreConfig(m_Config);
        // // Set the config also on client
        // GetDayZGame().SetConfig(m_Config);
        if (!m_Config.CRDTN_IntroMusic)
        {
            return;
        }
      
        DebugUtils.Log(CFG_CRDTN_Core_Prefix + " Client::RPC_ServerConfigReceived() received config from server");
    }

    void PlayIntroSong()
    {
        if (m_Config == null)
        {
            return;
        }
        if (!m_Config.CRDTN_IntroMusic)
        {
            return;
        }
        CRDTN_PluginBase.CRDTN_PlaySound(m_Config.CRDTN_IntroSoundSet, GetGame().GetPlayer());
    }
};

CRDTN_CorePluginClient GetCRDTN_CorePlugin()
{
    return CRDTN_CorePluginClient.Cast(GetPluginManager().GetPluginByType(CRDTN_CorePluginClient));
}