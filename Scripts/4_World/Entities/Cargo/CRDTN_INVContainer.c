/// @brief Base class for the invisible container which can be used for vairous purposes 
class CRDTN_INVContainer extends Container_Base
{
    override bool IsInventoryVisible() { return false; }
	override bool IsTakeable() { return false; }
	override bool CanPutInCargo( EntityAI parent ) { return false; }
    override bool CanPutIntoHands( EntityAI parent ){ return false; }
};