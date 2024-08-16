#pragma once
#include"weapon_and_equipment.h"
#include<iostream>
using namespace std;

class Bigkandao :public WeaponAndEquipment {
public:
	Bigkandao(int m_weapon_id = 5, string m_name = "bigkandao", int m_equipmentDamage = 5, int m_equipmentWeight = 2, int m_equipmentDefense = 2);

	virtual void showInformation();

	virtual int showWeightValue();
};