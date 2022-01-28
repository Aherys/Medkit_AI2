class DrugLightSymptom extends SymptomBase
{
	float tickTimer = 0;
	PPERequester_BloodLoss m_RequesterBloodLoss;
	
	//this is just for the Symptom parameters set-up and is called even if the Symptom doesn't execute, don't put any gameplay code in here
	override void OnInit()
	{
		m_SymptomType = SymptomTypes.PRIMARY;
		m_Priority = 1;
		m_ID = SymptomIDs_Extended.SYMPTOM_DRUG_LIGHT;
		m_SyncToClient = true;
		m_MaxCount = 2;
		m_Duration = 20;
		
		if ( !GetGame().IsDedicatedServer() )
		{
			Class.CastTo(m_RequesterBloodLoss,PPERequester_BloodLoss.Cast(PPERequesterBank.GetRequester(PPERequester_BloodLoss)));
		}
	}
	
	//!gets called every frame
	override void OnUpdateServer(PlayerBase player, float deltatime)
	{

	}

	override void OnUpdateClient(PlayerBase player, float deltatime)
	{
		
		m_RequesterBloodLoss.SetBloodLossLevel(5);
	}
	
	override void OnAnimationPlayFailed()
	{
		
	}
	
	override bool CanActivate()
	{
		return true;
	}
	
	//!gets called once on an Symptom which is being activated
	override void OnGetActivatedServer(PlayerBase player)
	{
		if (LogManager.IsSymptomLogEnable()) 
			Debug.SymptomLog("n/a", this.ToString(), "n/a", "OnGetActivated", m_Player.ToString());
		

		//player.AddHealth("","Shock",-10);
	}

	//!gets called once on a Symptom which is being activated
	override void OnGetActivatedClient(PlayerBase player)
	{

		if (LogManager.IsSymptomLogEnable()) Debug.SymptomLog("n/a", this.ToString(), "n/a", "OnGetActivated", m_Player.ToString());
	}

	//!only gets called once on an active Symptom that is being deactivated
	override void OnGetDeactivatedServer(PlayerBase player)
	{
		if (LogManager.IsSymptomLogEnable()) Debug.SymptomLog("n/a", this.ToString(), "n/a", "OnGetDeactivated", m_Player.ToString());
	}

	//!only gets called once on an active Symptom that is being deactivated
	override void OnGetDeactivatedClient(PlayerBase player)
	{
		if (LogManager.IsSymptomLogEnable()) Debug.SymptomLog("n/a", this.ToString(), "n/a", "OnGetDeactivated", m_Player.ToString());
		m_RequesterBloodLoss.Stop();
	}
}
