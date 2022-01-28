class CfgPatches
{
	class Medkit_AI2
	{
		units[] = {};																		// OSEF - pour les characters
		weapons[] = {};																		// OSEF
		requiredVersion = 0.1;																// Version du jeu - OSEF - meme BI OSEF
		requiredAddons[] = {"DZ_Data","DZ_Gear_Medical"};  									// Addon requis pour faire fonctionner l'item. Si classe externe utilisée, obligatoire sinon kaboom
	};
};

class CfgMods
{
 class WeaponBreakOnDie
 {
  type = "mod";
  
  class defs
  {
   class worldScriptModule
   {
    value = "";
    files[] = {"Medkit_AI2/WorldScripts"};
   };
  };
 };
};

class CfgVehicles 
{
	class BandageDressing; 																	// Classe externe issue de gear_medical\DZ\gear\medical\config.cpp

	class Medkit_AI2: BandageDressing 											// Classe de base de ton item - herite de la classe externe BandageDressing parce qu'on va pas tout redefinir. flemme.
	{
		scope = 0; 																			// Utilisé par l'editeur - 0=hidden; 1=Zeus; 2=Editor - zeus existe pas dans DayZ, useless.
		displayName = "Medkit AI-2 (Base)";													// Nom affiché en jeu - stringtable preferable
		model = "Medkit_AI2\Medkit_AI2_DZ.p3d";										// Chemin vers modele 3D - Backslash important
		weight = 100;																		// Poids de l'item - joues potentiellement sur le comportement de la physique de l'item si il est lancé
		descriptionShort = "Small medical box (Base)";										// Desc de l'item affiché en jeu - stringtable preferable
		varQuantityMax = 5;
		itemSize[] = {2,2};																	// Taille de l'item dans l'inventaire - largeur par longueur
        hiddenSelections[] = {"color"};													// Nom de la selection à utiliser dans le modele pour permettre le retexturing
        hiddenSelectionsTextures[] = {"Medkit_AI2\data\AI2_Yellow_co.paa"};					// Chemin vers les colors - utilisé pour permettre le retexturing - là par contre Backslash pas ouf

		class AnimEvents
		{
			class SoundWeapon
			{
				class BloodBag_start
				{
					soundSet = "BloodBag_start_SoundSet";
					id = 201;
				};
				class BloodBag_spear
				{
					soundSet = "BloodBag_spear_SoundSet";
					id = 202;
				};
				class BloodBag_loop
				{
					soundSet = "BloodBag_loop_SoundSet";
					id = 203;
				};
				class BloodBag_loop2
				{
					soundSet = "BloodBag_loop_SoundSet";
					id = 204;
				};
				class BloodBag_end
				{
					soundSet = "BloodBag_end_SoundSet";
					id = 205;
				};
				class pickUpItem
				{
					soundSet = "pickUpBloodBag_SoundSet";
					id = 797;
				};
				class drop
				{
					soundset = "bloodbag_drop_SoundSet";
					id = 898;
				};
			};
		};
	};

	class Medkit_AI2_Blue: Medkit_AI2	 									// Classe qu'on va vraiment utiliser du coup. Va etre affiché en jeu - hérite de la Base
	{
		scope = 2;
		displayName = "Medkit AI-2 (Blue)";
		model = "Medkit_AI2\Medkit_AI2_DZ.p3d";
		descriptionShort = "Small medical box (Blue)";
        hiddenSelections[] = {"color"};
        hiddenSelectionsTextures[] = {"Medkit_AI2\data\AI2_Blue_co.paa"};
	};
	class Medkit_AI2_Yellow: Medkit_AI2
	{
		scope = 2;
		displayName = "Medkit AI-2 (Yellow)";
		model = "Medkit_AI2\Medkit_AI2_DZ.p3d";
		descriptionShort = "Small medical box (Yellow)";
        hiddenSelections[] = {"color"};
        hiddenSelectionsTextures[] = {"Medkit_AI2\data\AI2_Yellow_co.paa"};
	};
	class Medkit_AI2_Green: Medkit_AI2
	{
		scope = 2;
		displayName = "Medkit AI-2 (Green)";
		model = "Medkit_AI2\Medkit_AI2_DZ.p3d";
		descriptionShort = "Small medical box (Green)";
        hiddenSelections[] = {"color"};
        hiddenSelectionsTextures[] = {"Medkit_AI2\data\AI2_Green_co.paa"};
	};
	class Medkit_AI2_Red: Medkit_AI2
	{
		scope = 2;
		displayName = "Medkit AI-2 (Red)";
		model = "Medkit_AI2\Medkit_AI2_DZ.p3d";
		descriptionShort = "Small medical box (Red)";
        hiddenSelections[] = {"color"};
        hiddenSelectionsTextures[] = {"Medkit_AI2\data\AI2_Red_co.paa"};
	};
};
