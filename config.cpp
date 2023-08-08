class CfgPatches
{
    ///--------------------------------------------
    ///
    ///--------------------------------------------
    class CRDTN_Core
    {
        units[] = {""};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {
            "DZ_Data",
            "DZ_Scripts",
            "DZ_Sounds_Effects"
        };
    };
};

class CfgMods
{
    class CRDTN_Core
    {
        name = "CRDTN Core Mod";
        credits = "";
        author = "freeman@foxapo.com";
        type = "mod";
        dependencies[] = {"Game",
                          "World",
                          "Mission"};
        dir = "CRDTN_Core";
        class defs
        {
            class gameScriptModule
            {
                value = "";
                files[] = {"CRDTN_Core/Scripts/3_Game"};
            };
            class worldScriptModule
            {
                value = "";
                files[] = {"CRDTN_Core/Scripts/4_World"};
            };
            class missionScriptModule
            {
                value = "";
                files[] = {"CRDTN_Core/Scripts/5_Mission"};
            };
            class imageSets
            {
                files[] = {};
            };
        };
    };
};

class Cfg_sUDE
{
    class Visual
    {
        class PPEffects
        {
            class DefaultValues
            {
                saturation = 5.0;
                // vignette_strength = 0.5;
                // saturation = 1.0;
                // vignette_strength = 0.0;
                // overlay_factor = 0.0;
                // bloom_threshold = 0.01;
                // bloom_steepness = 0.0;
                // bloom_intensity = 0.5;
                // lens_distort = 0.0;
                // lens_center_x = 0.0;
                // lens_center_y = 0.0;
                // lens_chrom_aber = 0.0;
                // motion_blur_power = 0.01;
                // motion_blur_intensity = 0.1;
                // motion_blur_mindepth = 0.8;
                // motion_blur_maxdepth = 0.9;
                // gauss_blur_intensity = 0.0;
                // radial_blur_power_x = 0.0;
                // radial_blur_power_y = 0.0;
                // radial_blur_offset_x = 0.0;
                // radial_blur_offset_y = 0.0;
                // chrom_aber_power_x = 0.0;
                // chrom_aber_power_y = 0.0;
                // film_grain_sharpness = 0.0;
                // film_grain_grain_size = 0.0;
                godrays_sun_intensity = 0.8;
                godrays_sun_overburn_intensity = 0.25;
                godrays_sun_overburn_start = 0.025;
                godrays_sun_overburn_end = 0.175;
                // godrays_sun_mask = 0.8;
                // godrays_sun_size = 0.15;
                godrays_sun_v_intensity = 0.75;
                godrays_sun_d_intensity = 0.60;
                // vignette_color[] = {0.0, 0.0, 0.0, 0.0};
                overlay_color[] = {0.0, 0.0, 0.0, 0.0};
                colorization[] = {1.0, 1.0, 0.5, 1.0};
            };
        };
    };
};

class CfgVehicles
{
};

class CfgSlots
{
};

class CfgWeapons
{
};

class CfgSoundSets
{
    class baseCharacter_SoundSet;
    #include "Data\music\music_sound_sets.hpp"
};

class CfgSoundShaders
{
    class baseCharacter_SoundShader;
    #include "Data\music\music_sound_shaders.hpp"
};
