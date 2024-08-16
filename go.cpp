#include<iostream>
using namespace std;
#include"workManager.h"



int main()
{

	WorkManager wm;
	bool exitloop = false;
	while (!exitloop)       // start menu
	{
		
		wm.showMenu();
		int show_menu_num;
		cin >> show_menu_num;
		switch (show_menu_num)
		{
		case 1:
			wm.addCharacter();
			wm.addCharacter();
			system("pause");
			wm.addWeapon();
			wm.addWeapon();
			wm.addWeapon();
			system("pause");
			wm.addAttribute();
			system("pause");
			exitloop = true;
			break;
		case 2:
			wm.showGameRule();
			system("pause");
			system("cls");
			break;
		case 3:
			wm.exitGame();
			break;
		default:
			break;
		}
		
	}
	
	int round_number = 0;
	while (round_number !=5)       // action menu;
	{
		wm.actionMenu();
		int action_menu_num;
		cin >> action_menu_num;
		switch (action_menu_num)
		{
		case 1:
			wm.beatMonsterGesra();
			wm.addWeapon();
			break;
		case 2:
			wm.showWeaponMenu();
			break;
		case 3:
			wm.showCharacterMenu();
			break;
		case 4:
			wm.showAttributeMenu();
			break;
		case 5:
			wm.exitGame();
			break;
		default:
			break;
		}
		round_number++;
	}
	




	return 0;
}