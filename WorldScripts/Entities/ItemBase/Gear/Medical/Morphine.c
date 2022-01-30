modded class Morphine: Inventory_Base
{
	override void OnApply(PlayerBase player)
	{
			super.OnApply(player);
			
			player.GetStatDrug().Set(player.GetStatDrug().Get() + 55);
			player.GetModifiersManager().ActivateModifier(eModifiersExtended.MDF_DRUG);
	}
};
