#pragma once
#include<iostream>
using namespace std;

class Attribute {
public:
	Attribute();

	virtual void showInformation() = 0;

	int m_attribute_id;
	string m_AttributeName;
	int m_CriticalHitDamage;
	int m_flash_damage;
	
};