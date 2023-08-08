class CRDTN_CorePlugin : CRDTN_PluginBase
{
    // play CRDTN_Core_SoundSet_Music_Zone when player joins

    private ref CRDTN_Config m_Config;

    ref ScriptInvoker EConfigUpdated = new ScriptInvoker();
    
    override void InitData()
    {
        m_Config = new CRDTN_Config();
        JsonFileLoader<CRDTN_Config>.JsonLoadFile(CFG_CRDTN_ConfigPath, m_Config);
        DebugUtils.Log("InitData() CRDTN_Core config loaded");
        DebugUtils.Log(m_Config.CRDTN_ServerName);
        DebugUtils.Log(m_Config.CRDTN_Notifications.ToString());
        DebugUtils.Log(m_Config.CRDTN_Debug.ToString());
        DebugUtils.Log(m_Config.CRDTN_IntroMusic.ToString());
        DebugUtils.Log(m_Config.CRDTN_IntroSoundSet);
        GetDayZGame().SetConfig(m_Config);
    }

    override void InitRPCs()
    {
         GetRPCManager().AddRPC(CFG_CRDTN_Core_Prefix, "RPC_ServerConfigReceived", this, SingleplayerExecutionType.Both);
    }

    CRDTN_Config GetConfig()
    {
        return m_Config;
    }
    
    /// @brief Received from the server on client
    /// @param type 
    /// @param ctx 
    /// @param sender 
    /// @param target 
    void RPC_ServerConfigReceived(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
    {

        if(GetGame().IsServer())
        {
            return;
        }

        Param1<ref CRDTN_Config> data;
        if (!ctx.Read(data)) return;

        if (type == CallType.Server)
        {
            return;
        }
        
        if (type == CallType.Client)
        {
            m_Config = data.param1;
        }

        if(m_Config == null)
        {
            return;
        }
        // Set the config also on client 
        GetDayZGame().SetConfig(m_Config);
        if(!m_Config.CRDTN_IntroMusic)
        {
            return;
        }
        CRDTN_PluginBase.CRDTN_PlaySound(m_Config.CRDTN_IntroSoundSet, GetGame().GetPlayer());
    }

    /// @brief Called from the server
    /// @param identity 
    /// @param player 
    void OnPlayerConnected(PlayerIdentity identity, PlayerBase player)
    {
        if(!GetGame().IsServer())
        {
            return;
        }        
        GetRPCManager().SendRPC(CFG_CRDTN_Core_Prefix, "RPC_ServerConfigReceived", new Param1<ref CRDTN_Config>(m_Config), true, identity);
    }
};

CRDTN_CorePlugin GetCRDTN_CorePlugin()
{
    return CRDTN_CorePlugin.Cast(GetPluginManager().GetPluginByType(CRDTN_CorePlugin));
}