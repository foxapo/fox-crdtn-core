class CRDTN_FileLogger
{

    static ref map<string, ref CRDTN_FileLogger> m_Instances = new map<string, ref CRDTN_FileLogger>;
    private string _path = "";
    private string _name = "<< [CRDTN Logger] >>"; //dontobf

    private bool _useDate = true;
    private bool _isInitialized = false;

    static CRDTN_FileLogger CreateInstance(string name)
    {
        if (m_Instances.Contains(name))
        {
            return m_Instances.Get(name);
        }

        autoptr CRDTN_FileLogger instance = new CRDTN_FileLogger(name);
        m_Instances.Insert(name, instance);

        return instance;
    }

    static CRDTN_FileLogger GetInstance(string name)
    {
        if (!m_Instances.Contains(name))
        {
            return CreateInstance(name);
        }
        return m_Instances.Get(name);
    }

    void CRDTN_FileLogger(string name)
    {
        _name = name;
        if(!FileExist(CFG_CRDTN_LogsFolder))
        {
            _isInitialized = false;
        }
        else
        {
            _isInitialized = true;
        }

        if(!_isInitialized)
        {
            return;
        }

        FileHandle file = OpenFile(GetPath(), FileMode.READ);
        if (file == 0)
        {
            file = OpenFile(GetPath(), FileMode.WRITE);
            FPrintln(file, "/* CRDTN FILE LOGGER INSTANCE */"); //dontobf
        }
        CloseFile(file);
    }

    void UseDate(bool state)
    {
        _useDate = state;
    }

    void Log(string txt, bool nothing = false)
    {
        if(!_isInitialized)
        {
            return;
        }

        FileHandle logFile = OpenFile(GetPath(), FileMode.APPEND);
        if (logFile != 0)
        {
            FPrintln(logFile, GetDate() + _name + " " + txt);
            CloseFile(logFile);
        }
    }

    private string GetPath()
    {
        return CFG_CRDTN_LogsFolder + "\\" + _name + ".log"; //dontobf
    }

    string GetDate(bool fileFriendly = false)
    {
        int year, month, day, hour, minute, second;

        GetYearMonthDay(year, month, day);
        GetHourMinuteSecond(hour, minute, second);

        string date = day.ToStringLen(2) + "." + month.ToStringLen(2) + "." + year.ToStringLen(4) + " " + hour.ToStringLen(2) + ":" + minute.ToStringLen(2) + ":" + second.ToStringLen(2);
        if (fileFriendly)
        {
            date.Replace(" ", "_"); //dontobf
            date.Replace(".", "-"); //dontobf
            date.Replace(":", "-"); //dontobf
        }

        if(!_useDate)
        {
            return "";
        }

        return "[" + date + "] "; //dontobf
    }
}