// 04.The_Zone.ogg
// 07.The_Invisible_Threat.ogg
// Oxido.mp3.ogg
// Tension_1_Draft02.mp3.ogg
// Tension_2_Draft01.mp3.ogg

class CRDTN_Core_SoundSet_Music_Base : baseCharacter_SoundSet
{
    volumeFactor = 0.6;
    frequencyRandomizer = 0;
    spatial = 1;
    doppler = 0;
    loop = 0;
};

class CRDTN_Core_SoundSet_Music_Zone : CRDTN_Core_SoundSet_Music_Base
{
    volumeFactor = 0.3;
    soundShaders[] = {"CRDTN_Core_SoundShader_Music_Zone"};
};

class CRDTN_Core_SoundSet_Music_InvisibleThreat : CRDTN_Core_SoundSet_Music_Base
{
    volumeFactor = 0.5;
    soundShaders[] = {"CRDTN_Core_SoundShader_Music_InvisibleThreat"};
};

class CRDTN_Core_SoundSet_Music_Oxido : CRDTN_Core_SoundSet_Music_Base
{
    volumeFactor = 0.6;
    soundShaders[] = {"CRDTN_Core_SoundShader_Music_Oxido"};
};

class CRDTN_Core_SoundSet_Music_Tension1 : CRDTN_Core_SoundSet_Music_Base
{
    soundShaders[] = {"CRDTN_Core_SoundShader_Music_Tension1"};
};

class CRDTN_Core_SoundSet_Music_Tension2 : CRDTN_Core_SoundSet_Music_Base
{
    soundShaders[] = {"CRDTN_Core_SoundShader_Music_Tension2"};
};

