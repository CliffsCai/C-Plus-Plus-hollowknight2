#pragma once
#include"attribute.h"
using namespace std;
#include<iostream>

class Flash : public Attribute {
public:
	Flash(int m_attribute_id = 2, string m_AttributeName = "flash", int  m_flash_damage = 2);

	void showInformation();

};