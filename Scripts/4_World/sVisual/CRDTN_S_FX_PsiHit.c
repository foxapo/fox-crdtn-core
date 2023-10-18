#ifdef S_VISUAL


class CRDTN_SV_PsiEffect : SPPEffectAnimated
{
    
    protected float m_PsiLevel = 0;

    override void onAnimate(float deltaTime)
    {
        float power = Math.AbsFloat(Math.Sin(getTime() * 2.5) / Math.Clamp(m_PsiLevel, 60, 100));
        setRadialBlur(power, power);
        setChromAber(power * 5);
    }

    void SetPsiLevel(float level)
    {
        m_PsiLevel = level;
    }

};

#endif