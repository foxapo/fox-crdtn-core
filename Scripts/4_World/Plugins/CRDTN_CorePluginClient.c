class CRDTN_CorePluginClient: CRDTN_CorePluginBase
{

    void CRDTN_CorePluginClient()
    {
        DebugUtils.Log(CFG_CRDTN_Core_Prefix + " Client::CRDTN_CorePluginClient()");
    }

    /* --------------------------------------------------    RPC    -------------------------------------------------- */

      /// @brief Stores the servers config in the memory - can be used for further setup based on the servers requirement
      /// @param type 
      /// @param ctx 
      /// @param sender 
      /// @param target 
    void RPC_ServerConfigReceived(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (type != CallType.Client)
            return;

        DebugUtils.Log(CFG_CRDTN_Core_Prefix + " Client::RPC_ServerConfigReceived()");
        Param1<ref CRDTN_Config> data;
        if (!ctx.Read(data))
        {
            return;
        }
        m_Config = data.param1;
        DebugUtils.Log(CFG_CRDTN_Core_Prefix + " Client::RPC_ServerConfigReceived() config -> " + m_Config);
        if (m_Config == null)
        {
            return;
        }
        g_Game.SetCRDTNCoreConfig(m_Config);
        DebugUtils.Log(CFG_CRDTN_Core_Prefix + " Client::RPC_ServerConfigReceived() received config from server");
        if(m_Config.CRDTN_IntroMusic)
        {
            PlayIntroSong();
            DebugUtils.Log(CFG_CRDTN_Core_Prefix + " Client::RPC_ServerConfigReceived() playing intro song");
        }
    }

      /// @brief Play sound on client
      /// @param type 
      /// @param ctx 
      /// @param sender 
      /// @param target 
    void RPC_PlaySoundOnClient(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (type != CallType.Client)
            return;

        DebugUtils.Log(CFG_CRDTN_Core_Prefix + " Client::RPC_PlaySoundOnClient()");
        Param1<string> data;
        if (!ctx.Read(data))
        {
            return;
        }

        CRDTN_PluginBase.CRDTN_PlaySound(data.param1, PlayerBase.Cast(GetGame().GetPlayer()));
    }

    void RPC_PlaySoundOnClientObject(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
    {
        if (type != CallType.Client)
            return;

        if(!target)
        {
            return;
        }

        DebugUtils.Log(CFG_CRDTN_Core_Prefix + " Client::RPC_PlaySoundOnClientObject()");
        Param2<Object, string> data;
        if (!ctx.Read(data))
        {
            return;
        }

        CRDTN_PluginBase.CRDTN_PlaySound(data.param2, data.param1);
    }

    /* --------------------------------------------------    INTERNAL    -------------------------------------------------- */

      /// @brief Client side method to play a sound on player
    protected void PlayIntroSong()
    {
        CRDTN_PluginBase.CRDTN_PlaySound(m_Config.CRDTN_IntroSoundSet, PlayerBase.Cast(GetGame().GetPlayer()));
    }

};

CRDTN_CorePluginClient GetCRDTN_CorePlugin()
{
    return CRDTN_CorePluginClient.Cast(GetPluginManager().GetPluginByType(CRDTN_CorePluginClient));
}