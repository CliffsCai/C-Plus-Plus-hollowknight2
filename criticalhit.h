#pragma once
#include"attribute.h"
using namespace std;
#include<iostream>

class Criticalhit : public Attribute {
public:
	Criticalhit(int m_attribute_id = 1, string m_AttributeName = "criticalhit", int m_CriticalHitDamage = 10);

	void showInformation();

};