#pragma once
#include"weapon_and_equipment.h"
#include<iostream>
using namespace std;

class Smallgrass :public WeaponAndEquipment {
public:
	Smallgrass(int m_weapon_id = 6, string m_name = "smallgrass", int m_equipmentDamage = 0, int m_equipmentWeight = 0, int m_equipmentDefense = 0);

	virtual void showInformation();

	virtual int showWeightValue();
};