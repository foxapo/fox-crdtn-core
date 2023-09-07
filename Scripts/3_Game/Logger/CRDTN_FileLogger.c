class CRDTN_FileLogger
{

    static ref map<string, ref CRDTN_FileLogger> m_Instances = new map<string, ref CRDTN_FileLogger>;
    private string _path = "";
    private string _name = "<< [CRDTN Logger] >>";

    private bool _useDate = true;

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
            MakeDirectory(CFG_CRDTN_LogsFolder);
        }

        FileHandle file = OpenFile(GetPath(), FileMode.READ);
        if (file == 0)
        {
            file = OpenFile(GetPath(), FileMode.WRITE);
            FPrintln(file, "/* CRDTN FILE LOGGER INSTANCE */");
        }
        CloseFile(file);
    }

    void UseDate(bool state)
    {
        _useDate = state;
    }

    void Log(string txt, bool nothing = false)
    {
        FileHandle logFile = OpenFile(GetPath(), FileMode.APPEND);
        if (logFile != 0)
        {
            FPrintln(logFile, GetDate() + _name + " " + txt);
            CloseFile(logFile);
        }
    }

    private string GetPath()
    {
        return CFG_CRDTN_LogsFolder + "\\" + _name + ".log";
    }

    string GetDate(bool fileFriendly = false)
    {
        int year, month, day, hour, minute, second;

        GetYearMonthDay(year, month, day);
        GetHourMinuteSecond(hour, minute, second);

        string date = day.ToStringLen(2) + "." + month.ToStringLen(2) + "." + year.ToStringLen(4) + " " + hour.ToStringLen(2) + ":" + minute.ToStringLen(2) + ":" + second.ToStringLen(2);
        if (fileFriendly)
        {
            date.Replace(" ", "_");
            date.Replace(".", "-");
            date.Replace(":", "-");
        }

        if(!_useDate)
        {
            return "";
        }

        return "[" + date + "] ";
    }
}