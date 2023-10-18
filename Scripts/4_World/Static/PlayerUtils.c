class CRDTN_PlayerUtils
{

    static const float PLAYER_RANGE_CHECK_THRESHOLD = 50;

    static void CheckPlayerInRange(EntityAI ent, float radius, out ref set<PlayerBase> players)
    {
        
        autoptr array<CargoBase> cargos = new array<CargoBase>;
        autoptr array<Object> objects = new array<Object>;

        players.Clear();

        GetGame().GetObjectsAtPosition3D(ent.GetPosition(), radius + PLAYER_RANGE_CHECK_THRESHOLD, objects, cargos);
        if(objects.Count() == 0)
        {
            return;
        }

        for(int i = 0; i < objects.Count(); i++)
        {
            Object nearObject = objects.Get(i);
            PlayerBase player = PlayerBase.Cast(nearObject);
            if(!player)
            {
                continue;
            }

            if(!player.IsAlive())
            {
                continue;
            }

            if(vector.Distance(player.GetPosition(), ent.GetPosition()) > radius)
            {
                continue;
            }

            if(players.Find(player) != -1)
            {
                continue;
            }

            players.Insert(player);
        }
    }
};