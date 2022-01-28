enum SymptomIDs_Extended : SymptomIDs {
	SYMPTOM_DRUG_LIGHT = 240,
	SYMPTOM_DRUG_HEAVY,
};

modded class SymptomManager
{
	override void Init()
	{
		super.Init();
		
		RegisterSymptom(new DrugHeavySymptom);
		RegisterSymptom(new DrugLightSymptom);
	}
}