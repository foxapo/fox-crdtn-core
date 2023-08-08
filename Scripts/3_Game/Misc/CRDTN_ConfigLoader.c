class CRDTN_ConfigLoader<Class T>
{
    static void Save(ref T dataInstance, string path)
    {
        JsonFileLoader<T>.JsonSaveFile(path, dataInstance);
    }

    static void Load(string path, out T dataInstance)
    {
        JsonFileLoader<T>.JsonLoadFile(path, dataInstance);
    }
};
