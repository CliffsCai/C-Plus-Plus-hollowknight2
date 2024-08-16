#include<iostream>
#include"hammer.h"
using namespace std;

Hammer::Hammer(int weapon_id, string name, int equipmentDamage, int equipmentWeight, int equipmentDefense) {
	this->m_weapon_id = weapon_id;
	this->m_name = name;
	this->m_equipmentDamage = equipmentDamage;
	this->m_equipmentWeight = equipmentWeight;
	this->m_equipmentDefense = equipmentDefense;

}

void Hammer::showInformation() {
	cout << "ÎäÆ÷ id : " << this->m_weapon_id << endl;
	cout << "ÎäÆ÷Ãû×Ö : Ê¯´¸ " << endl;
	cout << "ÉËº¦ : " << this->m_equipmentDamage << endl;
	cout << "ÖØÁ¿ : " << this->m_equipmentWeight << endl;
	cout << "·ÀÓùÖµ : " << this->m_equipmentDefense << endl;

}

int  Hammer::showWeightValue()
{
	return this->m_equipmentWeight;
}