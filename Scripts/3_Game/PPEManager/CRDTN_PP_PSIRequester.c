class CRDTN_PP_PSIRequester : CRDTN_PPERequester
{
    void SetPsiEffectBlur(float intensity)
    {
        SetTargetValueFloat(PostProcessEffectType.GaussFilter, PPEGaussFilter.PARAM_INTENSITY, true, intensity, 105, PPOperators.ADD_RELATIVE);
    }

    void SetPsiEffectChromAbr(float intensity)
    {
        SetTargetValueFloat(PostProcessEffectType.ChromAber, PPEChromAber.PARAM_POWERX, false, intensity, 105, PPOperators.SET);
        SetTargetValueFloat(PostProcessEffectType.ChromAber, PPEChromAber.PARAM_POWERY, false, intensity, 105, PPOperators.SET);
    }
};
