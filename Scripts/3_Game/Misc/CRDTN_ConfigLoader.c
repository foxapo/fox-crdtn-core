class CRDTN_ConfigLoader<ref Class T>
{
    static void Save(ref T dataInstance, string path)
    {
        JsonFileLoader<ref T>.JsonSaveFile(path, dataInstance);
    }

    static void Load(string path, out T dataInstance)
    {
        JsonFileLoader<ref T>.JsonLoadFile(path, dataInstance);
    }

    static bool Init(string path, out ref T dataInstance)
    {
        if (FileExist(path))
        {
            Load(path, dataInstance);
            return true;
        }
        else
        {
            Save(dataInstance, path);
            return false;
        }
    }
};
