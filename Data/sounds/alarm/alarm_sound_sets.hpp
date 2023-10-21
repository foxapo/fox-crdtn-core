// CRDTN_Core_SoundShader_Sound_Alarm
// CRDTN_Core_SoundShader_Sound_AgruWarning
// CRDTN_Core_SoundShader_Sound_Siren2
// CRDTN_Core_SoundShader_Sound_Siren1

class CRDTN_Core_SoundSet_Sound_AlarmBase : CRDTN_Core_SoundSet_Sound_Base
{
    volumeFactor = 1.0;
    frequencyFactor = 1;
    frequencyRandomizer = 0.5;
    spatial = 1;
    doppler = 1;
};

class CRDTN_Core_SoundSet_Sound_Alarm : CRDTN_Core_SoundSet_Sound_AlarmBase
{
    soundShaders[] = {"CRDTN_Core_SoundShader_Sound_Alarm"};
};

class CRDTN_Core_SoundSet_Sound_AgruWarning : CRDTN_Core_SoundSet_Sound_AlarmBase
{
    soundShaders[] = {"CRDTN_Core_SoundShader_Sound_AgruWarning"};
};

class CRDTN_Core_SoundSet_Sound_Siren2 : CRDTN_Core_SoundSet_Sound_AlarmBase
{
    soundShaders[] = {"CRDTN_Core_SoundShader_Sound_Siren2"};
};

class CRDTN_Core_SoundSet_Sound_Siren1 : CRDTN_Core_SoundSet_Sound_AlarmBase
{
    soundShaders[] = {"CRDTN_Core_SoundShader_Sound_Siren1"};
};