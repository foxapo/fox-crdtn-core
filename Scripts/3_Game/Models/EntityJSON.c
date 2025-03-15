class EntityJSON
{
	string id;
	int row, col, width, height, slotId;
	float health;
	string type;
	float quantity;
	bool isAmmo;
	int ammo;
	bool flip;
	bool isFood;
	int foodStage;
	string networkId;
	ref array<ref EntityJSON> attachments;
	ref array<ref EntityJSON> cargo;
};