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
			m_StatDrug = PlayerStat<float>.Cast(GetPlayerStats().GetStatObject(EPlayerStatsExtended_current.DRUG));
		}
		return m_StatDrug;
	}
}