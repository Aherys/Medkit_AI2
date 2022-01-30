modded class CharcoalTablets extends Edible_Base
{

	override void OnConsume(float amount, PlayerBase consumer)
	{
		super.OnConsume(amount, consumer);
		
		consumer.GetStatDrug().Set(consumer.GetStatDrug().Get() - 5);
		consumer.GetModifiersManager().ActivateModifier(eModifiersExtended.MDF_DRUG);
	}
}