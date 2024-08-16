#include<iostream>
#include"criticalhit.h"
using namespace std;

Criticalhit::Criticalhit(int attribute_id, string AttributeName, int CriticalHitDamage) {

	this->m_attribute_id = attribute_id;
	this->m_AttributeName = AttributeName;
	this->m_CriticalHitDamage = CriticalHitDamage;


}

void Criticalhit::showInformation() {
	cout << "ÊôÐÔÃû³Æ : »ðÑæËéÆ¬"  << endl;
	cout << "ÊôÐÔ : ±©»÷+"  << this->m_CriticalHitDamage << "% " << endl;
}