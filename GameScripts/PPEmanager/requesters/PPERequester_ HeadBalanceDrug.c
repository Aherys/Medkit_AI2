class PPERequester_HEADBALANCEDRUG extends PPERequester_GameplayBase
{
	void Update(float chrom_abb, float blur_power)
	{
		SetTargetValueFloat(PostProcessEffectType.ChromAber,PPEChromAber.PARAM_POWERX,false,chrom_abb,PPEChromAber.L_1_INTRO,PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.ChromAber,PPEChromAber.PARAM_POWERY,false,chrom_abb,PPEChromAber.L_1_INTRO,PPOperators.SET);
		
		SetTargetValueFloat(PostProcessEffectType.RadialBlur,PPERadialBlur.PARAM_POWERX, false, blur_power, PPERadialBlur.L_0_PAIN_BLUR, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.RadialBlur,PPERadialBlur.PARAM_POWERY, false, blur_power, PPERadialBlur.L_0_PAIN_BLUR, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.RadialBlur,PPERadialBlur.PARAM_OFFSETX, false, blur_power, PPERadialBlur.L_0_PAIN_BLUR, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.RadialBlur,PPERadialBlur.PARAM_OFFSETY, false, blur_power, PPERadialBlur.L_0_PAIN_BLUR, PPOperators.SET);
		SetTargetValueFloat(PostProcessEffectType.RadialBlur,PPERadialBlur.PARAM_PIXELSCALE, false, 0.5, PPERadialBlur.L_0_PAIN_BLUR, PPOperators.SET);
	}
}