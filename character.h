#pragma once
#include<iostream>
using namespace std;

class Character {
public:
	Character();

	virtual void showInformation() = 0;

	string m_CharacterName;
	int m_CharacterLifeValue;
	int m_WeightValue;

};