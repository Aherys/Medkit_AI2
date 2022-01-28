class DrugMdfr : ModifierBase
{
	const int LIFETIME = 240;
	const int ACTIVATION_DELAY = 15;
	
	override void Init()
	{
		m_TrackActivatedTime = true;
		m_IsPersistent = true;
		m_ID = eModifiersExtended.MDF_DRUG;
		m_TickIntervalInactive = DEFAULT_TICK_TIME_INACTIVE;
		m_TickIntervalActive = 1;
		DisableActivateCheck();
	}

	override bool ActivateCondition(PlayerBase player)
	{
		return false;
	}

	override void OnReconnect(PlayerBase player)
	{
		OnActivate(player);
	}

	override string GetDebugText()
	{
		return (LIFETIME - GetAttachedTime()).ToString();
	}


	override void OnActivate(PlayerBase player)
	{

	}

	override void OnDeactivate(PlayerBase player)
	{
		
	}

	override bool DeactivateCondition(PlayerBase player)
	{
		float attached_time = GetAttachedTime();

		if (player.GetStatDrug().GetMin() == player.GetStatDrug().Get())
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
		
		int ActualSymptomID = -1;
		if (player.GetSymptomManager().GetCurrentPrimaryActiveSymptom())
		{
			ActualSymptomID = player.GetSymptomManager().GetCurrentPrimaryActiveSymptom().GetType();
		}
		
		
		if (player.GetStatLevelDrug() > EStatLevels.MEDIUM && ActualSymptomID != SymptomIDs_Extended.SYMPTOM_DRUG_LIGHT)
			{
				player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs_Extended.SYMPTOM_DRUG_LIGHT);
			}
		
		if (player.GetStatLevelDrug() > EStatLevels.HIGH && ActualSymptomID != SymptomIDs_Extended.SYMPTOM_DRUG_HEAVY)
			{
				player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs_Extended.SYMPTOM_DRUG_LIGHT);
			}
		
		
		if (GetAttachedTime() > ACTIVATION_DELAY)
		{
			player.GetStatDrug().Set(ActualDrug - (2.0 * deltaT));
			Print("DrugLevel =" + (2.0 * deltaT));
		}
	}
};