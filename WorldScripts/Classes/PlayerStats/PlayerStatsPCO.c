enum EPlayerStatsExtended_current : EPlayerStats_current
{
	DRUG = 821344,
};

modded class PlayerStatsPCO_current
{

	override void Init()
	{
		super.Init();
		
		RegisterStat(EPlayerStatsExtended_current.DRUG,  	new PlayerStat<float>	(0,	100,								0,								"Drug",		EPSstatsFlags.EMPTY) );
	}
};

