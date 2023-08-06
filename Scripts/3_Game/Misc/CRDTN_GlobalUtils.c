class CRDTN_GlobalUtils
{

    /// @brief Helper method for parsing the long int steam id. Basically the steam ID is split into 3 parts and summarized in total.
    /// @param steamID
    /// @return
    static int ParseID(string steamID)
    {
        int steam_id_segment_a = steamID.Substring(0, 6).ToInt();
        int steam_id_segment_b = steamID.Substring(6, 6).ToInt();
        int steam_id_segment_c = steamID.Substring(12, 5).ToInt();
        return steam_id_segment_a + steam_id_segment_b + steam_id_segment_c;
    }

    /// @brief Helper method for getting the current year, month and day.
    static string GetDate(bool fileFriendly = false)
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

        return date;
    }

    static string ResolveTheme(string key)
    {
        switch(key)
        {
            case "default":
                return "CRDTN_Quests\\data\\themes\\default.edds";
            case "stalker":
                return "CRDTN_Quests\\data\\themes\\stalker.edds";
        }

        return "CRDTN_Quests\\data\\themes\\default.edds";
    }

};
