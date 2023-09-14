class CfgPatches
{
    class CRDTN_Core
    {
        units[]          = {""};
        weapons[]        = {};
        requiredVersion  = 0.1;
        requiredAddons[] = { "DZ_Data", "DZ_Scripts" };
        defines[]        = { "CRDTN_Core" };
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
        dependencies[] = { "Game", "World", "Mission" };
        dir = "CRDTN_Core";
        class defs
        {
            class gameScriptModule      {  files[] = {"CRDTN_Core/Scripts/3_Game"};    };
            class worldScriptModule     {  files[] = {"CRDTN_Core/Scripts/4_World"};   };
            class missionScriptModule   {  files[] = {"CRDTN_Core/Scripts/5_Mission"}; };
            class imageSets             {  files[] = {};                               };
        };
    };
};

class CfgVehicles
{

    class Inventory_Base;
    class Paper : Inventory_Base{};
    class CRDTN_KeyBase : Paper
    {
        scope = 0;
        inventorySlot[] = {""};
        itemSize[] = {2, 1};
        stackedUnit = "pc.";
        quantityBar = 1;
        canBeSplit=0;
        weight = 20;
        varQuantityInit = 1;
        varQuantityMin = 0;
        varQuantityMax = 1;
        varQuantityDestroyOnMin = 1;
        destroyOnEmpty = 1;
        weightPerQuantityUnit = 0.0;
    };

};