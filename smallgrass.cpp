#include<iostream>
#include"smallgrass.h"
using namespace std;

Smallgrass::Smallgrass(int weapon_id, string name, int equipmentDamage, int equipmentWeight, int equipmentDefense) {
	this->m_weapon_id = weapon_id;
	this->m_name = name;
	this->m_equipmentDamage = equipmentDamage;
	this->m_equipmentWeight = equipmentWeight;
	this->m_equipmentDefense = equipmentDefense;

}
void Smallgrass::showInformation() {
	cout << "���� id : " << this->m_weapon_id << endl;
	cout << "�������� : С�� " << endl;
	cout << "�˺� : " << this->m_equipmentDamage << endl;
	cout << "���� : " << this->m_equipmentWeight << endl;
	cout << "����ֵ : " << this->m_equipmentDefense << endl;

}

int  Smallgrass::showWeightValue()
{
	return this->m_equipmentWeight;
}