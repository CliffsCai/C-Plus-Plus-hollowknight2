#pragma once
#include"weapon_and_equipment.h"
#include<iostream>
using namespace std;

class Sword :public WeaponAndEquipment {
public:
	Sword(int m_weapon_id=1, string m_name= "sword", int m_equipmentDamage= 4, int m_equipmentWeight=2, int m_equipmentDefense=2);

	virtual void showInformation();

	virtual int showWeightValue();
};