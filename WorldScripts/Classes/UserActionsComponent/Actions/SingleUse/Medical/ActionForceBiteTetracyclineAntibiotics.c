modded class ActionForceBiteTetracyclineAntibiotics: ActionForceConsumeSingle
{
	override void ApplyModifiers( ActionData action_data )
	{
		super.ApplyModifiers( action_data );
		
		action_data.m_Player.GetStatDrug().Set(action_data.m_Player.GetStatDrug().Get() + 25);
		action_data.m_Player.GetModifiersManager().ActivateModifier(eModifiersExtended.MDF_DRUG);
	}
};