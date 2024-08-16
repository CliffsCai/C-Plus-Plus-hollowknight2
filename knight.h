#pragma once
#include"character.h"
using namespace std;
#include<iostream>

class Knight : public Character {
public:
	Knight(string m_CharacterName="knight", int m_CharacterLifeValue=20, int m_WeightValue=10);

	void showInformation();

};