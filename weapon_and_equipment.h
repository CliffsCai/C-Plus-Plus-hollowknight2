#pragma once
#include<iostream>
using namespace std;

class WeaponAndEquipment {
public:
	WeaponAndEquipment();

	virtual void showInformation() = 0;

	virtual int showWeightValue() = 0;

	int m_weapon_id;
	string m_name;
	int m_equipmentDamage;
	int m_equipmentWeight;
	int m_equipmentDefense;


	int m_equipmentXixuezhi;

};