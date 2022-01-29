enum EPlayerStatsExtended_v115 : EPlayerStats_v115
{
	DRUG,
};

modded class PlayerStatsPCO_v115 extends PlayerStatsPCO_Base
{

	override void Init()
	{
		super.Init();
		
		RegisterStat(EPlayerStatsExtended_v115.DRUG,  	new PlayerStat<float>	(0,	100,								0,								"Drug",		EPSstatsFlags.EMPTY) );
	}
};

enum EPlayerStatsExtended_current : EPlayerStatsExtended_v115
{
	
};