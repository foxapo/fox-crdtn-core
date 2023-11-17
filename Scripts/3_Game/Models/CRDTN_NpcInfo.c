/// @brief Data wrapper for the NPC definition
class CRDTN_NpcInfo
{
    ref map<string, string> Data = new map<string, string>();

    const string NPC_INFO_NPC_NAME = "NpcName";
    
    string GetParam(string key)
    {
        if (Data == null)
        {
            return "";
        }

        if (Data.Contains(key))
        {
            return Data.Get(key);
        }
        else
        {
            return "";
        }
    }

    void SetParam(string key, string value)
    {
        if(Data == null)
        {
            Data = new map<string, string>();
        }

        Data.Set(key, value);
    }
};