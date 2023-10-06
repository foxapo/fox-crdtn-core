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

    class CRDTN_SurvivorM_Mirek : SurvivorM_Mirek{};
    class CRDTN_SurvivorM_Boris : SurvivorM_Boris{};
    class CRDTN_SurvivorM_Cyril : SurvivorM_Cyril{};
    class CRDTN_SurvivorM_Denis : SurvivorM_Denis{};
    class CRDTN_SurvivorM_Elias : SurvivorM_Elias{};
    class CRDTN_SurvivorM_Francis : SurvivorM_Francis{};
    class CRDTN_SurvivorM_Guo : SurvivorM_Guo{};
    class CRDTN_SurvivorM_Hassan : SurvivorM_Hassan{};
    class CRDTN_SurvivorM_Indar : SurvivorM_Indar{};
    class CRDTN_SurvivorM_Jose : SurvivorM_Jose{};
    class CRDTN_SurvivorM_Kaito : SurvivorM_Kaito{};
    class CRDTN_SurvivorM_Lewis : SurvivorM_Lewis{};
    class CRDTN_SurvivorM_Manua : SurvivorM_Manua{};
    class CRDTN_SurvivorM_Niki : SurvivorM_Niki{};
    class CRDTN_SurvivorM_Oliver : SurvivorM_Oliver{};
    class CRDTN_SurvivorM_Peter : SurvivorM_Peter{};
    class CRDTN_SurvivorM_Quinn : SurvivorM_Quinn{};
    class CRDTN_SurvivorM_Rolf : SurvivorM_Rolf{};
    class CRDTN_SurvivorM_Seth : SurvivorM_Seth{};
    class CRDTN_SurvivorM_Taiki : SurvivorM_Taiki{};
    class CRDTN_SurvivorF_Eva : SurvivorF_Eva{};
    class CRDTN_SurvivorF_Frida : SurvivorF_Frida{};
    class CRDTN_SurvivorF_Gabi : SurvivorF_Gabi{};
    class CRDTN_SurvivorF_Helga : SurvivorF_Helga{};
    class CRDTN_SurvivorF_Irena : SurvivorF_Irena{};
    class CRDTN_SurvivorF_Judy : SurvivorF_Judy{};
    class CRDTN_SurvivorF_Keiko : SurvivorF_Keiko{};
    class CRDTN_SurvivorF_Linda : SurvivorF_Linda{};
    class CRDTN_SurvivorF_Maria : SurvivorF_Maria{};
    class CRDTN_SurvivorF_Naomi : SurvivorF_Naomi{};
    class CRDTN_SurvivorF_Baty : SurvivorF_Baty{};
};