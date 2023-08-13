class CRDTN_PluginBase : PluginBase
{
    protected bool m_IsInitialized = false;

    override void OnInit()
    {
        super.OnInit();
        InitRPCs();
        InitData();
        ParseData();
    }

    bool IsInitialized()
    {
        return m_IsInitialized;
    }

    void InitRPCs();
    
    void InitData();
    
    void ParseData();

    /// @brief Use thsi method to play a certain soundset on the player (clientside)
    /// @param soundSet 
    /// @param player 
    static void CRDTN_PlaySound(string soundSet, Object object)
    {
        EffectSound m_sound = SEffectManager.PlaySoundOnObject(soundSet, object);
        m_sound.SetSoundAutodestroy(true);
    }
};