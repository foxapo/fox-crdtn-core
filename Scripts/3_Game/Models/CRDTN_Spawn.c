class CRDTN_Spawn
{
    ref array<ref CRDTN_Location> SpawnLocations = new array<ref CRDTN_Location>();
    ref array<ref CRDTN_NpcLocation> NpcLocations = new array<ref CRDTN_NpcLocation>();

    static void Save(string path, ref CRDTN_Spawn dataInstance)
    {
        JsonFileLoader<ref CRDTN_Spawn>.JsonSaveFile(path, dataInstance);
    }

    static void Load(string path, out CRDTN_Spawn dataInstance)
    {
        JsonFileLoader<ref CRDTN_Spawn>.JsonLoadFile(path, dataInstance);
        if(!dataInstance)
        {
            dataInstance = new CRDTN_Spawn();
            JsonFileLoader<ref CRDTN_Spawn>.JsonSaveFile(path, dataInstance);
        }
    }
};