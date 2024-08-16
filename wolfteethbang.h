#pragma once
#include"weapon_and_equipment.h"
#include<iostream>
using namespace std;

class Wolfteethbang :public WeaponAndEquipment {
public:
	Wolfteethbang(int m_weapon_id = 7, string m_name = "wolfteethbang", int m_equipmentDamage = 6, int m_equipmentWeight = 4, int m_equipmentDefense = 3);

	virtual void showInformation();

	virtual int showWeightValue();
};