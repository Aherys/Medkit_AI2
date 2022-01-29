class DrugLightSymptom extends SymptomBase
{
	PPERequester_DRUG m_Requester;
	
	//this is just for the Symptom parameters set-up and is called even if the Symptom doesn't execute, don't put any gameplay code in here
	override void OnInit()
	{
		m_SymptomType = SymptomTypes.SECONDARY;
		m_Priority = 1;
		m_ID = SymptomIDs_Extended.SYMPTOM_DRUG_LIGHT;
		m_SyncToClient = true;
		m_MaxCount = 1;
		m_IsPersistent = true;
		
		if( !GetGame().IsDedicatedServer() )
		{
			Class.CastTo(m_Requester, PPERequesterBank.GetRequester(PPERequester_DRUG));
			m_Requester.Start();
		}
	}
	
	//!gets called every frame
	override void OnUpdateServer(PlayerBase player, float deltatime)
	{

	}

	override void OnUpdateClient(PlayerBase player, float deltatime)
	{
		
		float ActualDrug = player.GetTransferValues().GetDrug() * 100;
		if (ActualDrug >= 25)
		{
			float blur = ActualDrug >= 25;
			float chrom = ActualDrug >= 50;
			
			m_Requester.Update(chrom, blur);
		}
		else
		{
			m_Requester.Stop();
		}
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

	}
}
