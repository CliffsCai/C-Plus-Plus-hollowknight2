#pragma once
#include"weapon_and_equipment.h"
#include<iostream>
using namespace std;

class Hammer :public WeaponAndEquipment {
public:
	Hammer(int m_weapon_id = 3, string m_name = "hammer", int m_equipmentDamage = 6, int m_equipmentWeight = 3, int m_equipmentDefense = 1);

	virtual void showInformation();

	virtual int showWeightValue();
};