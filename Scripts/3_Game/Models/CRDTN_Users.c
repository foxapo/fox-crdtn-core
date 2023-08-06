// Users
class CRDTN_Users
{
    ref array<ref CRDTN_User> Users;
};

class CRDTN_User
{
    string Id; 
    string SteamId;
    string PlayerName;
    string Description;
    string RegistrationDate;

    string PrintData()
    {
        return "User: " + PlayerName + " (" + Description + ")";
    }
};


class CRDTN_UserClient
{
    string Id; 
    string PlayerName;
};