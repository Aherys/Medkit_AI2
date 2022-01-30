modded class AntiChemInjector: Inventory_Base
{
	override void OnApply(PlayerBase player)
	{
			super.OnApply(player);
			
			player.GetStatDrug().Set(0);
			player.GetModifiersManager().ActivateModifier(eModifiersExtended.MDF_DRUG);
	}
};
