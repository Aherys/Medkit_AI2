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
   }
  }
 }
}

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
		itemSize[] = {2,2};																	// Taille de l'item dans l'inventaire - largeur par longueur
        hiddenSelections[] = {"texture"};													// Nom de la selection à utiliser dans le modele pour permettre le retexturing
        hiddenSelectionsTextures[] = {"Medkit_AI2\data\main_base_co.paa"};					// Chemin vers les textures - utilisé pour permettre le retexturing - là par contre Backslash pas ouf
	};

	class Medkit_AI2_Blue: Medkit_AI2	 									// Classe qu'on va vraiment utiliser du coup. Va etre affiché en jeu - hérite de la Base
	{
		scope = 2;
		displayName = "Medkit AI-2 (Blue)";
		descriptionShort = "Small medical box (Blue)";
        hiddenSelections[] = {"texture"};
        hiddenSelectionsTextures[] = {"Medkit_AI2\data\main_blue_co.paa"};
	};
};
