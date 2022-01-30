class ChemXMdfr: ModifierBase
{
	const int CHEMX_LIFETIME = 60;
	
	override void Init()
	{
		m_TrackActivatedTime = true;
		m_IsPersistent = true;
		m_ID 					= eModifiersExtended.MDF_CHEMX;
		m_TickIntervalInactive 	= DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive 	= 3;
		DisableActivateCheck();
	}

	override bool ActivateCondition(PlayerBase player)
	{
		return false;
	}
	
	override void OnReconnect(PlayerBase player)
	{
		OnActivate( player );
	}
	
	override string GetDebugText()
	{
		return ( CHEMX_LIFETIME - GetAttachedTime() ).ToString();
	}

	
	override void OnActivate(PlayerBase player)
	{
		player.IncreaseHealingsCount();
		/*
		if ( player.GetNotifiersManager() )
			player.GetNotifiersManager().ActivateByType(eNotifiers.NTF_PILLS);
		*/
	}
	
	override void OnDeactivate(PlayerBase player)
	{
		player.DecreaseHealingsCount();
		/*
		if ( player.GetNotifiersManager() )
			player.GetNotifiersManager().DeactivateByType(eNotifiers.NTF_PILLS);
		*/
	}
	
	override bool DeactivateCondition(PlayerBase player)
	{
		float attached_time = GetAttachedTime();
		
		if ( attached_time >= CHEMX_LIFETIME )
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	override void OnTick(PlayerBase player, float deltaT)
	{
		float ActualDrug = player.GetStatDrug().Get();
		
		if ( GetAttachedTime() < CHEMX_LIFETIME )
		{		
			player.GetStatDrug().Set(ActualDrug - (2 * deltaT));
		}
	}
};