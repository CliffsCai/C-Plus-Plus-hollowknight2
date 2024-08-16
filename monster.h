#pragma once
#include<iostream>
using namespace std;

class Monster {
public:
	Monster();

	virtual void showInformation() = 0;


	string m_MonsterName;
	int m_MonsterLifeValue;
	int m_MonsterDamage;
};