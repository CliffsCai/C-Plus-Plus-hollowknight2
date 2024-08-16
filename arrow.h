#pragma once
#include"weapon_and_equipment.h"
#include<iostream>
using namespace std;

class Arrow :public WeaponAndEquipment {
public:
	Arrow(int m_weapon_id = 4, string m_name = "arrow", int m_equipmentDamage = 5, int m_equipmentWeight = 1, int m_equipmentDefense = 0);

	virtual void showInformation();

	virtual int showWeightValue();
};