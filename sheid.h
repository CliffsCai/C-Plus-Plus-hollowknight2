#pragma once
#include"weapon_and_equipment.h"
#include<iostream>
using namespace std;

class Sheid :public WeaponAndEquipment {
public:
	Sheid(int m_weapon_id = 2, string m_name = "sheid", int m_equipmentDamage = 1, int m_equipmentWeight = 2, int m_equipmentDefense = 6);

	virtual void showInformation();

	virtual int showWeightValue();
};