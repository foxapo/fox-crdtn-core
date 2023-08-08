class DebugUtils
{
    static bool CFG_Debug = true;

    static void Log(string message, bool overridePrint = false)
    {
        if(overridePrint)
        {
            Print(CFG_CRDTN_MAIN_PREFIX + message);
            return;
        }
        if (!CFG_Debug)
        {
            return;
        }
        Print(CFG_CRDTN_MAIN_PREFIX + message);
    }

    static void LogTrace(string message)
    {
        if (!CFG_Debug)
        {
            return;
        }

        DebugPrint.LogAndTrace(CFG_CRDTN_MAIN_PREFIX + message);
    }

};