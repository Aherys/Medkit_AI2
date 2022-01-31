modded class PlayerBase extends ManBase
{
	
	protected PlayerStat<float> m_StatDrug;
	
	EStatLevels GetStatLevelDrug()
	{
		float drug = GetStatDrug().Get();
		return GetStatLevel(drug, PlayerConstants.SL_HEALTH_CRITICAL, PlayerConstants.SL_HEALTH_LOW, PlayerConstants.SL_HEALTH_NORMAL, PlayerConstants.SL_HEALTH_HIGH);
	}
	
	float GetStatBordersDrug()
	{
		float Drug = GetStatDrug().Get();
		float Drug_max = GetStatDrug().GetMax();
		return GetStatLevelBorders(Drug, PlayerConstants.SL_HEALTH_CRITICAL, PlayerConstants.SL_HEALTH_LOW, PlayerConstants.SL_HEALTH_NORMAL, PlayerConstants.SL_HEALTH_HIGH, Drug_max);
	}
	
	PlayerStat<float> GetStatDrug()
	{
		if( !m_StatDrug && GetPlayerStats() )
		{			
			for(int i = 0; i < 2147483646; i++)
			{
				m_StatDrug = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(i));
				if (m_StatDrug && m_StatDrug.GetLabel())
				{
					if (m_StatDrug.GetLabel() == "Drug")
					{
						break;
					}
				}
				m_StatDrug = null;
			}
		}
		return m_StatDrug;
	}
}