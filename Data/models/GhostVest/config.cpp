class CfgPatches
{
	class DZ_Characters_Vests
	{
		units[] = {
			"TacticalVest",
			"UKAssVest"};
		weapons[] = {};
		requiredVersion = 0.1;
		requiredAddons[] =
			{
				"DZ_Characters"};
	};
};
class CfgVehicles
{
	class Clothing_Base;
	class Clothing : Clothing_Base {};
	class HighCapacityVest_Black;
	class CRDTN_PlateVest_ColorBase : HighCapacityVest_Black
	{
		scope = 2;
		displayName = "Plate Vest";
		descriptionShort = "";
		model = "CRDTN_Core\Data\models\GhostVest\vest_g.p3d";
		inventorySlot = "Vest";
		simulation = "clothing";
		vehicleClass = "Clothing";
		itemInfo[] = {"Clothing", "Vest"};
		attachments[] = {"VestGrenadeA", "VestGrenadeB", "VestGrenadeC", "VestGrenadeD"};
		weight = 5000;
		itemSize[] = {4, 3};
		itemsCargoSize[] = {7, 7};
		quickBarBonus = 6;
		absorbency = 0.1;
		heatIsolation = 0.25;
		repairableWithKits[] = {5, 3};
		repairCosts[] = {30, 25};
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"\CRDTN_Core\Data\models\GhostVest\tex\tacvest1_1_co.paa"};

		class ClothingTypes
		{
			male = "\CRDTN_Core\Data\models\GhostVest\vest.p3d";
			female = "\CRDTN_Core\Data\models\GhostVest\vest.p3d";
		};

		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints = 50;
					healthLevels[] =
						{

							{1,

							 {"DZ\characters\vests\Data\PressVest.rvmat"}},

							{0.69999999,

							 {"DZ\characters\vests\Data\PressVest.rvmat"}},

							{0.5,

							 {"DZ\characters\vests\Data\PressVest_damage.rvmat"}},

							{0.30000001,

							 {"DZ\characters\vests\Data\PressVest_damage.rvmat"}},

							{0,

							 {"DZ\characters\vests\Data\PressVest_destruct.rvmat"}}};
				};
			};
			class GlobalArmor
			{
				class Projectile
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
				class Melee
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
				class Infected
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
				class FragGrenade
				{
					class Health
					{
						damage = 0.5;
					};
					class Blood
					{
						damage = 0;
					};
					class Shock
					{
						damage = 0.5;
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class pickUpItem
				{
					soundSet = "Shirt_pickup_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "Shirt_drop_SoundSet";
					id = 898;
				};
			};
		};
	};
	class CRDTN_PlateVest_Bandit : CRDTN_PlateVest_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] =
			{
				"\CRDTN_Core\Data\models\GhostVest\tex\tacvest1_bandit.paa"};
	};
	class CRDTN_PlateVest_Dolg : CRDTN_PlateVest_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] =
			{
				"\CRDTN_Core\Data\models\GhostVest\tex\tacvest1_dolg.paa"};
	};
	class CRDTN_PlateVest_Svoboda : CRDTN_PlateVest_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] =
			{
				"\CRDTN_Core\Data\models\GhostVest\tex\tacvest1_free.paa"};
	};
	class CRDTN_PlateVest_Merc : CRDTN_PlateVest_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] =
			{
				"\CRDTN_Core\Data\models\GhostVest\tex\tacvest1_merc.paa"};
	};
	class CRDTN_PlateVest_Monolit : CRDTN_PlateVest_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] =
			{
				"\CRDTN_Core\Data\models\GhostVest\tex\tacvest1_monolit.paa"};
	};
	class CRDTN_PlateVest_Neutral : CRDTN_PlateVest_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] =
			{
				"\CRDTN_Core\Data\models\GhostVest\tex\tacvest1_neutral.paa"};
	};
	class CRDTN_PlateVest_Stalker : CRDTN_PlateVest_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] =
			{
				"\CRDTN_Core\Data\models\GhostVest\tex\tacvest1_stalker.paa"};
	};
	class CRDTN_PlateVest_Voen : CRDTN_PlateVest_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] =
			{
				"\CRDTN_Core\Data\models\GhostVest\tex\tacvest1_voen.paa"};
	};
	class CRDTN_PlateVest_Prapor : CRDTN_PlateVest_ColorBase
	{
		scope = 2;
		hiddenSelectionsTextures[] =
			{
				"\CRDTN_Core\Data\models\GhostVest\tex\tacvest1_1_co.paa"};
	};
};
