#pragma once
#include<iostream>
#include"monster.h"
using namespace std;

class Gesra : public Monster {
public:
	Gesra(string m_MonsterName = "gesra", int m_MonsterLifeValue = 20, int m_MonsterDamage = 2);

	virtual void showInformation();


};