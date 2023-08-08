class CfgPatches
{
    class CRDTN_CoreMusic
    {
        units[] = {""};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] =
            {
                "DZ_Data",
                "DZ_Scripts",
                "DZ_Sounds_Effects"};
    };
};

class CfgSoundSets
{
    class baseCharacter_SoundSet;
    class CRDTN_Core_SoundSet_Music_Base : baseCharacter_SoundSet
    {
        volumeFactor = 0.6;
        frequencyRandomizer = 0;
        spatial = 1;
        doppler = 0;
        loop = 0;
    };
    #include "music_sound_sets.hpp"
};

class CfgSoundShaders
{
    class baseCharacter_SoundShader;
    class CRDTN_Core_SoundShader_Music_Base : baseCharacter_SoundShader
    {
        volume = 1;
        range = 20;
        rangeCurve[] =
            {
                {0, 1},
                {0.5, 0.69999999},
                {1, 0}};
    };
    #include "music_sound_shaders.hpp"
};
