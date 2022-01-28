class ActionHealingBase: ActionContinuousBase
{	
	
	private bool CanBeHealed(PlayerBase Target)
	{
		bool result = false;

		result = Target && Target.IsAlive();
		// return  result =  Target.GetHealth() != Target.GetMaxHealth();
		return true;
	} 

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( target)
		{
			PlayerBase target_player = PlayerBase.Cast(target.GetObject());
			if(target_player)
				{
					return CanBeHealed(target_player);
				}
		}
		return CanBeHealed(player);
		
	}
	
	void ApplyHealing( ItemBase item, PlayerBase player )
	{	

		player.AddHealth("","", player.GetMaxHealth() * 0.15);
		player.GetStatDrug().Set(player.GetStatDrug().Get() + 30);
		player.GetModifiersManager().ActivateModifier(eModifiersExtended.MDF_DRUG);
		
		PluginTransmissionAgents m_mta = PluginTransmissionAgents.Cast(GetPlugin(PluginTransmissionAgents));
		m_mta.TransmitAgents(item, player, AGT_ITEM_TO_FLESH);
		
		if (item.HasQuantity())
		{
			item.AddQuantity(-1,true);
		}
		else
		{
			item.Delete();
		}
	}
};