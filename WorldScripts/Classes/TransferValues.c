modded class TransferValues extends Managed
{
	const int TYPE_DRUG 	= 55;
	
	float m_LastDrugUpdate;
	float m_DrugMaxValue;
	float m_DrugClient;
	
	override void Init()
	{
		super.Init();
		
		m_LastDrugUpdate 	= 0;
		m_DrugMaxValue 	= 	m_Player.GetStatDrug().GetMax();
		m_DrugClient 		= 0;
	}
	
		override void CheckValues()
	{
		super.CheckValues();
		
		CheckDrug();
	}
	
	float GetDrug()
	{
		return m_DrugClient;
		
	}
	
	void CheckDrug()
	{
		float drug_current = m_Player.GetStatDrug().Get();

		float drug_normalized = Math.InverseLerp(0, m_DrugMaxValue, drug_current);
		drug_normalized = Math.Clamp(drug_normalized,0,1);
		float difference_normalized = drug_normalized - m_LastDrugUpdate;
		float diff_abs = Math.AbsFloat(difference_normalized);
		
		if( diff_abs > ( 0.1 /100 ) )
		{
			SendValue(TYPE_DRUG, drug_normalized);
			m_LastDrugUpdate = drug_normalized;
		}
	}
	
	override void ReceiveValue(int value_type, float value)
	{
		
		super.ReceiveValue(value_type, value);
		
		if( value_type == TYPE_DRUG )
		{
			m_DrugClient = value;
		}
	}
	
}