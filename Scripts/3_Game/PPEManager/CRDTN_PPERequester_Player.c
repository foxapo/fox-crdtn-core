enum CRDTN_PPEffect
{
    GausBlur,
    ChromAbr
};

class CRDTN_PPERequester_Player extends PPERequester_GameplayBase
{
    void ResetToDefault()
    {
        SetTargetValueFloat(PostProcessEffectType.GaussFilter, PPEGaussFilter.PARAM_INTENSITY, true, 0, 105, PPOperators.SET);
        SetTargetValueFloat(PostProcessEffectType.ChromAber, PPEChromAber.PARAM_POWERX, false, 0, 105, PPOperators.SET);
    }

    void SetGausBlur(float intensity)
    {
        SetTargetValueFloat(PostProcessEffectType.GaussFilter, PPEGaussFilter.PARAM_INTENSITY, true, intensity, 105, PPOperators.ADD_RELATIVE);
    }

    void SetChromAbr(float intensity)
    {
        SetTargetValueFloat(PostProcessEffectType.ChromAber, PPEChromAber.PARAM_POWERX, false, intensity, 105, PPOperators.ADD_RELATIVE);
    }

    void SetPsiEffectBlur(float intensity)
    {
        SetTargetValueFloat(PostProcessEffectType.GaussFilter, PPEGaussFilter.PARAM_INTENSITY, true, intensity, 105, PPOperators.ADD_RELATIVE);
    }

    void SetPsiEffectChromAbr(float intensity)
    {
        SetTargetValueFloat(PostProcessEffectType.ChromAber, PPEChromAber.PARAM_POWERX, false, intensity, 105, PPOperators.SET);
        SetTargetValueFloat(PostProcessEffectType.ChromAber, PPEChromAber.PARAM_POWERY, false, intensity, 105, PPOperators.SET);
    }
}