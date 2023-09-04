class RestApiResponse<Class T>
{
    string requestType;
    string uniqueId = "";
    T data;

    RestApiRequestType GetRequestType()
    {
        return typename.StringToEnum(RestApiRequestType, requestType);
    }

    string GetUniqueId()
    {
        return uniqueId;
    }

    T GetData()
    {
        return data;
    }
}