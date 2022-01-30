modded class ModifiersManager
{

	override void Init()
	{
		super.Init();
		AddModifier(new DrugMdfr);
		AddModifier(new ChemXMdfr);
	}
}
