modded class PlayerBase
{
    protected CRDTN_PPERequester_Player m_CreatureEffects;

    private bool m_PsiEffectActive = false;
    private bool m_PPEffectsReset = false;

#ifdef S_VISUAL
    ref CRDTN_SV_PsiEffect m_PsiEffect;
#endif

    void PlayerBase()
    {
        if(GetGame().IsClient())
        {
        #ifdef S_VISUAL
                m_PsiEffect = new CRDTN_SV_PsiEffect();
        #endif
        }
    }

    override void OnSelectPlayer()
    {
        super.OnSelectPlayer();
        if (GetGame().IsClient())
        {
            m_CreatureEffects = PPERequesterBank.GetRequester(CRDTN_PPERequester_Player);
        }
    }

    void RequestPPEChange(CRDTN_PPEffect effect, float value)
    {
        if(!m_PsiEffectActive)
        {
            OnPsiAttackStarted();
        }

        switch (effect)
        {
            case CRDTN_PPEffect.GausBlur:
                m_CreatureEffects.SetGausBlur(value);
                break;
            case CRDTN_PPEffect.ChromAbr:
                #ifdef S_VISUAL
                    Print("Setting chromaberration to " + value);
                    m_PsiEffect.SetPsiLevel(value);
                #endif
                DayZPlayerCameraBase camera = DayZPlayerCameraBase.Cast(this.GetCurrentCamera());
		        camera.SpawnCameraShakeProper(value * 0.2, 3, 0.3, 1.0);
                break;
        }
    }

    void ResetPPE()
    {
        m_CreatureEffects.ResetToDefault();
        #ifdef S_VISUAL
        m_PsiEffect.SetPsiLevel(0);
        OnPsiAttackStopped();
        #endif
        m_PPEffectsReset = false;
    }

    void OnPsiAttackStarted()
    {
        m_PsiEffectActive = true;
        // CHeck if reset in in call queue
        if (!m_PPEffectsReset) 
        {
            GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(ResetPPE, 30000, false);
            m_PPEffectsReset = true;
        }

        #ifdef S_VISUAL
        if (GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT) {
			SPPEManager.activate(m_PsiEffect);
		}
        #endif
    }

    void OnPsiAttackStopped()
    {
        m_PsiEffectActive = false;
        #ifdef S_VISUAL
        if (GetInstanceType() == DayZPlayerInstanceType.INSTANCETYPE_CLIENT) {
            SPPEManager.deactivate(m_PsiEffect);
        }
        #endif
    }

    
};