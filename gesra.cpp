#include<iostream>
#include"gesra.h"
using namespace std;

Gesra::Gesra(string MonsterName, int MonsterLifeValue, int MonsterDamage) {

	this->m_MonsterLifeValue = MonsterLifeValue;
	this->m_MonsterName = MonsterName;
	this->m_MonsterDamage = MonsterDamage;

}

void Gesra::showInformation() {
	cout << "姓名 : 哥斯拉" << endl;
	cout << "生命值 : " << this->m_MonsterLifeValue << endl;
	cout << "伤害 : " << this->m_MonsterDamage << endl;
}