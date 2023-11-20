modded class MissionServer
{
    override void OnInit()
    {
        super.OnInit();
        if (!GetCRDTN_CorePluginServer())
        {
            return;
        }
        GetCRDTN_CorePluginServer().InitMission(CRDTN_GetServerHostName());
    }

    override void InvokeOnConnect(PlayerBase player, PlayerIdentity identity)
    {
        super.InvokeOnConnect(player, identity);
        if (!GetCRDTN_CorePluginServer())
        {
            return;
        }

        // DebugUtils.Log(CFG_CRDTN_Core_Prefix + ": Sending config to player");
        GetCRDTN_CorePluginServer().OnPlayerConnected(identity, player);

        if (!GetCRDTN_CorePluginServer().GetConfig())
        {
            DebugUtils.Log(CFG_CRDTN_Core_Prefix + ": Intro notification disabled");
            return;
        }

        if (GetCRDTN_CorePluginServer().GetConfig().CRDTN_DisableIntroNotification)
        {
            DebugUtils.Log(CFG_CRDTN_Core_Prefix + ": Intro notification disabled");
            return;
        }

        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SendWelcomeNotification, 5000, false, identity);
        GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SendMessageToPlayer, 5000, false, player);
    }

    /// @brief This method can be also called from different mods. You can override and leave it empty if you want to get rid of the welcome notification
    /// @param identity
    void SendWelcomeNotification(PlayerIdentity identity)
    {
        // DebugUtils.Log(CFG_CRDTN_Core_Prefix + ": CRDTN_Core Sending welcome notification");
        NotificationSystem.SendNotificationToPlayerIdentityExtended(identity, 3, "Welcome survivor!", "Welcome to " + CRDTN_GetServerHostName(), "set:ui_news image:news1"); //dontobf
    }

    void SendMessageToPlayer(PlayerBase player)
    {
        player.MessageAction(" >> You're playing on a server powered by CRDTN Core << ");
        // GetCRDTN_CorePluginServer().PlaySoundOnClient(player, "CRDTN_SoundSet_StalkerSounds_Pda_Welcome");
    }

    /// @brief CREDITS: VPP ADMIN TOOLS 
    private string CRDTN_GetServerHostName()
    {
        string cfgPath;
        GetGame().CommandlineGetParam("config", cfgPath);
        string fullPathToConfig;

        if (cfgPath == string.Empty)
        {
            fullPathToConfig = "$CurrentDir:serverDZ.cfg"; // default
        }
        else if (cfgPath.Substring(1, 2) == ":\\")  //dontobf
        {
            array<string> output = {};
            cfgPath.Split("\\", output);
            if (output && output.Count() > 0)
            {
                fullPathToConfig = string.Format("$CurrentDir:%1\\%2", output[output.Count() - 2], output[output.Count() - 1]);  //dontobf
            }
        }
        else
        {
            fullPathToConfig = "$CurrentDir:" + cfgPath;
        }

        if (!FileExist(fullPathToConfig))
        {
            fullPathToConfig = "$CurrentDir:serverDZ.cfg";  //dontobf
        }

        FileHandle serverCfg = OpenFile(fullPathToConfig, FileMode.READ);
        if (serverCfg != 0)
        {
            array<string> cfgData = new array<string>;
            string line_content = "";
            int char_count = FGets(serverCfg, line_content);
            cfgData.Insert(line_content);

            while (char_count != -1)
            {
                cfgData.Insert(line_content);
                char_count = FGets(serverCfg, line_content);
            }
            CloseFile(serverCfg);

            // Parse and find server name
            foreach (string line : cfgData)
            {
                while (line.Contains(" "))
                {
                    line.Replace(" ", "");
                    line.TrimInPlace();
                }

                if (line.Length() >= 10)
                {
                    string tmpLine = line.Substring(0, 10);
                    if (tmpLine == "hostname=\"") //dontobf
                    {
                        int strIndex;
                        while (line[strIndex] != string.Empty)
                        {
                            if (line[strIndex] == "\"" && line[strIndex + 1] != string.Empty)  //dontobf
                            {
                                if (line[strIndex + 1] == ";")
                                {
                                    string dirtyName = line.Substring(0, strIndex);
                                    dirtyName.Replace("hostname=\"", "");  //dontobf
                                    Print(dirtyName);
                                    return dirtyName;
                                }
                            }
                            strIndex++;
                        }
                    }
                }
            }
        }
        return "[SERVER NAME NOT FOUND]";
    }
};