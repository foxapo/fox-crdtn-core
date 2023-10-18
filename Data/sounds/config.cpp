class CfgPatches
{
    class CRDTN_CoreSounds
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
    class CRDTN_Core_SoundSet_Sound_Base : baseCharacter_SoundSet
    {
        volumeFactor = 0.6;
        frequencyRandomizer = 0;
        spatial = 1;
        doppler = 0;
        loop = 0;
    };

    class CRDTN_SoundSet_StalkerSounds_Pda_Base : baseCharacter_SoundSet
    {
        volumeFactor = 0.6;
        frequencyRandomizer = 0;
        spatial = 1;
        doppler = 0;
        loop = 0;
    };

    class CRDTN_SoundSet_StalkerSounds_Ambient_Base : baseCharacter_SoundSet
    {
        volumeFactor = 0.5;
        frequencyRandomizer = 0;
        spatial = 1;
        doppler = 0;
        loop = 0;
    };

    #include "core_sound_sets.hpp"
    #include "pda\pda_sound_sets.hpp"
    #include "ambient\ambient_sound_sets.hpp"
};

class CfgSoundShaders
{
    class baseCharacter_SoundShader;
    class CRDTN_Core_SoundShader_Sound_Base : baseCharacter_SoundShader
    {
        volume = 1;
        range = 20;
        rangeCurve[] =
            {
                {0, 1},
                {0.5, 0.69999999},
                {1, 0}};
    };

    class CRDTN_SoundShader_StalkerSounds_Pda_Base : baseCharacter_SoundShader
    {
        volume = 1;
        range = 20;
        rangeCurve[] =
            {
                {0, 1},
                {0.5, 0.69999999},
                {1, 0}};
    };

    class CRDTN_SoundShader_StalkerSounds_Ambient_Base : baseCharacter_SoundShader
    {
        volume = 0.7;
        range = 40;
        rangeCurve[] =
            {
                {0, 1},
                {0.5, 0.69999999},
                {1, 0}};
    };

    #include "core_sound_shaders.hpp"
    #include "pda\pda_sound_shaders.hpp"
    #include "ambient\ambient_sound_shaders.hpp"
};

class CfgSounds
{
    #include "pda\pda_sounds.hpp"
};
