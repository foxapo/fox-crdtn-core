typedef CRDTN_PlayerUtils PlayerUtils;
class CRDTN_PlayerUtils
{
    static const float PLAYER_RANGE_CHECK_THRESHOLD = 50;
    static void CheckPlayerInRange(EntityAI ent, float radius, out set<PlayerBase> players)
    {

        autoptr array<CargoBase> cargos = new array<CargoBase>;
        autoptr array<Object> objects = new array<Object>;

        players.Clear();

        GetGame().GetObjectsAtPosition3D(ent.GetPosition(), radius + PLAYER_RANGE_CHECK_THRESHOLD, objects, cargos);
        if (objects.Count() == 0)
        {
            return;
        }

        for (int i = 0; i < objects.Count(); i++)
        {
            Object nearObject = objects.Get(i);
            PlayerBase player = PlayerBase.Cast(nearObject);
            if (!player)
            {
                continue;
            }

            if (!player.IsAlive())
            {
                continue;
            }

            if (vector.Distance(player.GetPosition(), ent.GetPosition()) > radius)
            {
                continue;
            }

            if (players.Find(player) != -1)
            {
                continue;
            }

            players.Insert(player);
        }
    }

    static PlayerIdentity GetIdentityById(string id)
    {
        if (GetGame().IsServer())
        {
            autoptr array<Man> players = new array<Man>;
            GetGame().GetWorld().GetPlayerList(players);

            for (int i = 0; i < players.Count(); ++i)
            {
                PlayerIdentity identity = players.Get(i).GetIdentity();
                if (identity != NULL)
                {
                    if (identity.GetPlainId() == id || identity.GetId() == id)
                    {
                        return identity;
                    }
                }
            }
            return NULL;
        }

        return NULL;
    }

    static PlayerBase GetPlayerByIdentity(PlayerIdentity identity)
    {
        if (GetGame().IsServer())
        {
            int networkIdLowBits;
            int networkIdHighBits;
            GetGame().GetPlayerNetworkIDByIdentityID(identity.GetPlayerId(), networkIdLowBits, networkIdHighBits);
            return PlayerBase.Cast(GetGame().GetObjectByNetworkId(networkIdLowBits, networkIdHighBits));
        }

        return NULL;
    }

    static PlayerBase GetPlayerBySteamId(string id)
    {
        if (GetGame().IsServer())
        {
            PlayerIdentity identity = GetIdentityById(id);
            if (identity == NULL)
                return NULL;
            int networkIdLowBits;
            int networkIdHighBits;
            GetGame().GetPlayerNetworkIDByIdentityID(identity.GetPlayerId(), networkIdLowBits, networkIdHighBits);
            return PlayerBase.Cast(GetGame().GetObjectByNetworkId(networkIdLowBits, networkIdHighBits));
        }

        return NULL;
    }

    static PlayerIdentity GetIdentityBySteamId(string id)
    {
        if (GetGame().IsServer())
        {
            PlayerBase player = GetPlayerBySteamId(id);
            if (player == NULL)
                return NULL;
            return player.GetIdentity();
        }

        return NULL;
    }
}
