modded class AntiChemInjector: Inventory_Base
{
	override void OnApply(PlayerBase player)
	{
			super.OnApply(player);
			
			player.GetModifiersManager().ActivateModifier(eModifiersExtended.MDF_DRUG);
			player.GetModifiersManager().ActivateModifier(eModifiersExtended.MDF_CHEMX);
	}
};
