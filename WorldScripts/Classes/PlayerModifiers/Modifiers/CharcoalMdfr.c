modded class CharcoalMdfr: ModifierBase
{

	override void OnTick(PlayerBase player, float deltaT)
	{
		super.OnTick(player, deltaT);
		float ActualDrug = player.GetStatDrug().Get();	

		if ( GetAttachedTime() < CHARCOAL_LIFETIME )
		{		
			player.GetStatDrug().Set(ActualDrug - (0.3 * deltaT));
		}
		
	}
};