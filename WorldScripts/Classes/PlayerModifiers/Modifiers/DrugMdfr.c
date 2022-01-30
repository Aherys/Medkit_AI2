class DrugMdfr : ModifierBase
{
	const int ACTIVATION_DELAY = 15;
	float mTimerLastDebuffProcc = 45;
	float mTimerLastHitProcc = 25;
	bool bDrugHeavyHasBeenTrigger = false;
	bool bDrugLightHasBeenTrigger = false;
	bool bLastTickBeforeStopModifier = false;
	
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
		return "";
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

		if (player.GetStatDrug().GetMin() >= player.GetStatDrug().Get() && !bLastTickBeforeStopModifier)
		{
			bLastTickBeforeStopModifier = true;
			return false;
		}
		else if (player.GetStatDrug().GetMin() >= player.GetStatDrug().Get() && bLastTickBeforeStopModifier)
		{
			bLastTickBeforeStopModifier = false;
			return true;
		}
		else
		{
			bLastTickBeforeStopModifier = false;
			return false;
		}
	}

	override void OnTick(PlayerBase player, float deltaT)
	{
		float ActualDrug = player.GetStatDrug().Get();
		mTimerLastDebuffProcc -= deltaT;
		mTimerLastHitProcc -= deltaT;
		
		// Drug Reduction overtime
		if (GetAttachedTime() > ACTIVATION_DELAY)
		{
			player.GetStatDrug().Set(ActualDrug - (0.1 * deltaT));

		}
		
		// Handeling Hits
		if (player.GetStatLevelDrug() <= 2 && mTimerLastHitProcc <= 0)
		{
			player.DecreaseHealth("", "Shock", ActualDrug / 3);
			mTimerLastHitProcc = 25;
		}
		
		
		// Handeling Other Symptom on OD
		if (player.GetStatLevelDrug() <= 2 && mTimerLastDebuffProcc <= 0)
		{
			int Rand = Math.RandomInt(0,5);
			
			if (Rand == 0)
			{
				player.GetSymptomManager().QueueUpPrimarySymptom(SymptomIDs_Extended.SYMPTOM_VOMIT);
				player.GetStatDrug().Set(ActualDrug - 10);
			}
			else if (Rand == 1 && player.GetStatDrug().Get() >= 80)
				player.DecreaseHealth("", "Shock", 100);
			else if (Rand == 2 && player.GetStatDrug().Get() >= 70)
				player.DecreaseHealth("", "Shock", 40);
			
			
			if (player.GetStatLevelDrug() <= 1)
			{
				mTimerLastDebuffProcc = 15;
			}
			else 
			{
				mTimerLastDebuffProcc = 45;
			}
		}
		
		// Light Symptom Trigger
		if (!bDrugLightHasBeenTrigger)
		{
			player.GetSymptomManager().QueueUpSecondarySymptom(SymptomIDs_Extended.SYMPTOM_DRUG_LIGHT);
			bDrugLightHasBeenTrigger = true;
		}
		else if (bDrugLightHasBeenTrigger)
		{
			player.GetSymptomManager().RemoveSecondarySymptom(SymptomIDs_Extended.SYMPTOM_DRUG_LIGHT);
			bDrugLightHasBeenTrigger = false;
		}

		// Heavy Symptom Trigger
		if (player.GetStatLevelDrug() < 2 && !bDrugHeavyHasBeenTrigger)
		{
			player.GetSymptomManager().QueueUpSecondarySymptom(SymptomIDs_Extended.SYMPTOM_DRUG_HEAVY);
			bDrugHeavyHasBeenTrigger = true;
		}
		else if (bDrugHeavyHasBeenTrigger)
		{
			player.GetSymptomManager().RemoveSecondarySymptom(SymptomIDs_Extended.SYMPTOM_DRUG_HEAVY);
			bDrugHeavyHasBeenTrigger = false;
		}
		
		// Heart Attack code
		if (player.GetStatLevelDrug() == 0)
		{
			player.SetHealth("", "Shock", 0);
			player.DecreaseHealth( "", "Blood", 250 * deltaT );
		}
	}
};