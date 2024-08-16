#pragma once
#include<iostream>
using namespace std;
#include"weapon_and_equipment.h"
#include"character.h"
#include<fstream>
#include"monster.h"
#include"attribute.h"
#define FILENAME1 "character.txt"
#define FILENAME2 "weapon.txt"
#define FILENAME3 "attribute.txt"

class WorkManager {
public:
	WorkManager();

	void showMenu();
	void actionMenu();

	void showCharacterMenu();
	void addCharacter();
	int m_characterNum;
	Character** m_CharacterArray;

	int  getCharacterNum();

	void showWeaponMenu();
	void addWeapon();
	int m_weaponNum;
	WeaponAndEquipment** m_WeaponArray;

	WeaponAndEquipment* addAnyweapon(int weapon_id, WeaponAndEquipment* weapon);

	bool verify_weight(int weapon_id);

	int  getWeaponNum();

	void showAttributeMenu();
	void addAttribute();
	int m_attributeNum;
	Attribute** m_AttributeArray;

	int  getAttributeNum();


	void init_weaponArray();
	void init_characterArray();
	void init_attributeArray();

	void exchange_weapon(int weapon_id);
	void exchange_character(string name);

	void saveCharacterFile();

	void saveWeaponFile();

	void saveAttribute();

	void beatMonsterGesra();

	void beatMonster(Monster* monster);

	void exitGame();

	void showGameRule();

	int getRandomNum();

	int ifCritiacl(int rate);

	bool haveWeapon();
	

	~WorkManager();

};