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
            date.Replace(" ", "_"); //dontobf
            date.Replace(".", "-"); //dontobf
            date.Replace(":", "-"); //dontobf
        }

        return date;
    }

    static string ResolveTheme(string key)
    {
        switch (key)
        {
        case "default-orange":
            return "CRDTN_Quests\\data\\themes\\default-orange.png";
        case "default":
            return "CRDTN_Quests\\data\\themes\\default.edds";
        case "stalker":
            return "CRDTN_Quests\\data\\themes\\stalker.edds";
        }
        // IF YOU WANT TO ADD NEW THEME - CONTACT ME AND WE CAN MAKE IT
        return "CRDTN_Quests\\data\\themes\\default.edds";
    }

    /// @brief Transform the given json data string from Rest-API response to a valid Enum type of RestApiRequestType
    /// @param value
    /// @return value of RestApiRequestType enum
    static RestApiRequestType GetRequestType(string value, out string unique_id)
    {
        unique_id = "";                   //dontobf
        string rtsi = "\"requestType\":"; //dontobf
        string rtei = "\"uniqueId\":";    //dontobf
        string usi = "\"";//dontobf
        string uei = "\"";//dontobf
        int requestTypeStartIndex = value.IndexOf(rtsi) + 15;
        int requestTypeEndIndex = value.IndexOfFrom(requestTypeStartIndex, usi);
        int uniqueIdStartIndex = value.IndexOf(rtei) + 12;
        int uniqueIdEndIndex = value.IndexOfFrom(uniqueIdStartIndex, uei);
        string requestTypeString = value.Substring(requestTypeStartIndex, requestTypeEndIndex - requestTypeStartIndex);
        unique_id = value.Substring(uniqueIdStartIndex, uniqueIdEndIndex - uniqueIdStartIndex);
        return typename.StringToEnum(RestApiRequestType, requestTypeString);
    }
};