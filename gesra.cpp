#include<iostream>
#include"gesra.h"
using namespace std;

Gesra::Gesra(string MonsterName, int MonsterLifeValue, int MonsterDamage) {

	this->m_MonsterLifeValue = MonsterLifeValue;
	this->m_MonsterName = MonsterName;
	this->m_MonsterDamage = MonsterDamage;

}

void Gesra::showInformation() {
	cout << "���� : ��˹��" << endl;
	cout << "����ֵ : " << this->m_MonsterLifeValue << endl;
	cout << "�˺� : " << this->m_MonsterDamage << endl;
}