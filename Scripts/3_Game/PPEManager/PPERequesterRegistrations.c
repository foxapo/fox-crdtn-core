modded class PPERequesterRegistrations
{
    void PPERequesterRegistrations()
    {
        PPERequesterBank.RegisterRequester(CRDTN_PPERequester_Player);
#ifdef S_VISUAL

        PPERequesterBank.RegisterRequester(CRDTN_SV_PsiEffect);
#endif
    }
}