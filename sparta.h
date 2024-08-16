#pragma once
#include"character.h"
using namespace std;
#include<iostream>

class Sparta : public Character {
public:
	Sparta(string m_CharacterName = "sparta", int m_CharacterLifeValue = 25, int m_WeightValue= 8);

	void showInformation();

};