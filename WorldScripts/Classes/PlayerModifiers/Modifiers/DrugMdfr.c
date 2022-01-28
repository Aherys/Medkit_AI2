class DrugMdfr : ModifierBase
{
	const int ACTIVATION_DELAY = 15;
	float mTimerLastDebuffProcc = 60;
	bool bDrugHeavyHasBeenTrigger = false;
	bool bHeartAttkHasBeenTrigger = false;
	
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

		if (player.GetStatDrug().GetMin() == player.GetStatDrug().Get())
		{
			Print("Desactivate");
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
		mTimerLastDebuffProcc -= deltaT;
		Print("Drug "+ ActualDrug +" L"+player.GetStatLevelDrug());
		if (GetAttachedTime() > ACTIVATION_DELAY)
		{
			player.GetStatDrug().Set(ActualDrug - (0.5 * deltaT));

		}
		
		ref SymptomManager SyMa = player.GetSymptomManager();
		
		if (!SyMa)
			return;
		
		
		if (player.GetStatLevelDrug() <= 2 && mTimerLastDebuffProcc <= 0)
		{
			int Rand = Math.RandomInt(0,5);
			
			if (Rand == 0)
				SyMa.QueueUpPrimarySymptom(SymptomIDs_Extended.SYMPTOM_VOMIT);
			else if (Rand == 1 && player.GetStatLevelDrug() == 1)
				player.SetHealth("", "Shock", 0);
			else if (Rand == 2)
				player.SetHealth("", "Shock", 30);
			
			
			if (player.GetStatLevelDrug() <= 1)
			{
				mTimerLastDebuffProcc = 15;
			}
			else 
			{
				mTimerLastDebuffProcc = 60;
			}
		}
		

		if (player.GetStatLevelDrug() < 2 && !bDrugHeavyHasBeenTrigger)
		{
			SyMa.QueueUpSecondarySymptom(SymptomIDs_Extended.SYMPTOM_DRUG_HEAVY);
			bDrugHeavyHasBeenTrigger = true;
		}
		else if (bDrugHeavyHasBeenTrigger)
		{
			SyMa.RemoveSecondarySymptom(SymptomIDs_Extended.SYMPTOM_DRUG_HEAVY);
			bDrugHeavyHasBeenTrigger = false;
		}
		
		if (player.GetStatLevelDrug() == 0 && !bHeartAttkHasBeenTrigger)
		{
			player.SetHealth("", "", 0);
			bHeartAttkHasBeenTrigger = true;
		}

	}
};