class CfgPatches
{
    class CRDTN_Core
    {
        units[] = {""};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"DZ_Data", "DZ_Scripts", "DZ_Characters", "JM_CF_Scripts"};
        defines[] = {"CRDTN_Core"};
    };
};

class CfgMods
{
    /// @brief CORE module for other mods - contains various methods and utilities for easier maintenance of mods and consistent behaviour
    class CRDTN_Core
    {
        name = "CRDTN Core Mod";
        credits = "";
        author = "freeman@foxapo.com";
        type = "mod";
        dependencies[] = {"Game", "World", "Mission"};
        dir = "CRDTN_Core";
        class defs
        {
            class gameScriptModule
            {
                files[] = {"CRDTN_Core/Scripts/3_Game"};
            };
            class worldScriptModule
            {
                files[] = {"CRDTN_Core/Scripts/4_World"};
            };
            class missionScriptModule
            {
                files[] = {"CRDTN_Core/Scripts/5_Mission"};
            };
            class imageSets
            {
                files[] = {};
            };
        };
    };
};

class CfgVehicles
{
    class Container_Base;
    class Inventory_Base;
    class Paper : Inventory_Base
    {
    };
    class CRDTN_KeyBase : Paper
    {
        scope = 0;
        inventorySlot[] = {""};
        itemSize[] = {2, 1};
        stackedUnit = "pc.";
        quantityBar = 1;
        canBeSplit = 0;
        weight = 20;
        varQuantityInit = 1;
        varQuantityMin = 0;
        varQuantityMax = 1;
        varQuantityDestroyOnMin = 1;
        destroyOnEmpty = 1;
        weightPerQuantityUnit = 0.0;
    };

    // ! NPCs ! //

    class SurvivorM_Mirek;
    class SurvivorM_Boris;
    class SurvivorM_Cyril;
    class SurvivorM_Denis;
    class SurvivorM_Elias;
    class SurvivorM_Francis;
    class SurvivorM_Guo;
    class SurvivorM_Hassan;
    class SurvivorM_Indar;
    class SurvivorM_Jose;
    class SurvivorM_Kaito;
    class SurvivorM_Lewis;
    class SurvivorM_Manua;
    class SurvivorM_Niki;
    class SurvivorM_Oliver;
    class SurvivorM_Peter;
    class SurvivorM_Quinn;
    class SurvivorM_Rolf;
    class SurvivorM_Seth;
    class SurvivorM_Taiki;
    class SurvivorF_Eva;
    class SurvivorF_Frida;
    class SurvivorF_Gabi;
    class SurvivorF_Helga;
    class SurvivorF_Irena;
    class SurvivorF_Judy;
    class SurvivorF_Keiko;
    class SurvivorF_Linda;
    class SurvivorF_Maria;
    class SurvivorF_Naomi;
    class SurvivorF_Baty;

    class CRDTN_SurvivorM_Mirek : SurvivorM_Mirek
    {
        scope = 2;
    };
    class CRDTN_SurvivorM_Boris : SurvivorM_Boris
    {
        scope = 2;
    };
    class CRDTN_SurvivorM_Cyril : SurvivorM_Cyril
    {
        scope = 2;
    };
    class CRDTN_SurvivorM_Denis : SurvivorM_Denis
    {
        scope = 2;
    };
    class CRDTN_SurvivorM_Elias : SurvivorM_Elias
    {
        scope = 2;
    };
    class CRDTN_SurvivorM_Francis : SurvivorM_Francis
    {
        scope = 2;
    };
    class CRDTN_SurvivorM_Guo : SurvivorM_Guo
    {
        scope = 2;
    };
    class CRDTN_SurvivorM_Hassan : SurvivorM_Hassan
    {
        scope = 2;
    };
    class CRDTN_SurvivorM_Indar : SurvivorM_Indar
    {
        scope = 2;
    };
    class CRDTN_SurvivorM_Jose : SurvivorM_Jose
    {
        scope = 2;
    };
    class CRDTN_SurvivorM_Kaito : SurvivorM_Kaito
    {
        scope = 2;
    };
    class CRDTN_SurvivorM_Lewis : SurvivorM_Lewis
    {
        scope = 2;
    };
    class CRDTN_SurvivorM_Manua : SurvivorM_Manua
    {
        scope = 2;
    };
    class CRDTN_SurvivorM_Niki : SurvivorM_Niki
    {
        scope = 2;
    };
    class CRDTN_SurvivorM_Oliver : SurvivorM_Oliver
    {
        scope = 2;
    };
    class CRDTN_SurvivorM_Peter : SurvivorM_Peter
    {
        scope = 2;
    };
    class CRDTN_SurvivorM_Quinn : SurvivorM_Quinn
    {
        scope = 2;
    };
    class CRDTN_SurvivorM_Rolf : SurvivorM_Rolf
    {
        scope = 2;
    };
    class CRDTN_SurvivorM_Seth : SurvivorM_Seth
    {
        scope = 2;
    };
    class CRDTN_SurvivorM_Taiki : SurvivorM_Taiki
    {
        scope = 2;
    };
    class CRDTN_SurvivorF_Eva : SurvivorF_Eva
    {
        scope = 2;
    };
    class CRDTN_SurvivorF_Frida : SurvivorF_Frida
    {
        scope = 2;
    };
    class CRDTN_SurvivorF_Gabi : SurvivorF_Gabi
    {
        scope = 2;
    };
    class CRDTN_SurvivorF_Helga : SurvivorF_Helga
    {
        scope = 2;
    };
    class CRDTN_SurvivorF_Irena : SurvivorF_Irena
    {
        scope = 2;
    };
    class CRDTN_SurvivorF_Judy : SurvivorF_Judy
    {
        scope = 2;
    };
    class CRDTN_SurvivorF_Keiko : SurvivorF_Keiko
    {
        scope = 2;
    };
    class CRDTN_SurvivorF_Linda : SurvivorF_Linda
    {
        scope = 2;
    };
    class CRDTN_SurvivorF_Maria : SurvivorF_Maria
    {
        scope = 2;
    };
    class CRDTN_SurvivorF_Naomi : SurvivorF_Naomi
    {
        scope = 2;
    };
    class CRDTN_SurvivorF_Baty : SurvivorF_Baty
    {
        scope = 2;
    };

    class CRDTN_INVContainer : Container_Base
    {
        scope = 2;
        displayName = "Invisible Container";
        descriptionShort = "Used for various purposes";
        model = "DZ\structures\Residential\Misc\Misc_BoxWooden.p3d";
        rotationFlags = 2;
        weight = 1000000;
        itemSize[] = {3, 4};
        itemsCargoSize[] = {10, 100};
        canBeDigged = 0;
        isMeleeWeapon = 1;
        storageCategory = 10;
        allowOwnedCargoManipulation = 1;
        randomQuantity = 2;
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 999999999;
                    healthLevels[] = {{1.0, {"DZ\gear\camping\data\wooden_case.rvmat"}}, {0.7, {"DZ\gear\camping\data\wooden_case.rvmat"}}, {0.5, {"DZ\gear\camping\data\wooden_case_damage.rvmat"}}, {0.3, {"DZ\gear\camping\data\wooden_case_damage.rvmat"}}, {0.0, {"DZ\gear\camping\data\wooden_case_destruct.rvmat"}}};
                };
            };
            class GlobalArmor
            {
                class FragGrenade
                {
                    class Health
                    {
                        damage = 8.0;
                    };
                    class Blood
                    {
                        damage = 8.0;
                    };
                    class Shock
                    {
                        damage = 8.0;
                    };
                };
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class pickUpItem
                {
                    soundSet = "smallprotectorcase_pickup_SoundSet";
                    id = 797;
                };
                class drop
                {
                    soundset = "smallprotectorcase_drop_SoundSet";
                    id = 898;
                };
            };
        };
    };
};