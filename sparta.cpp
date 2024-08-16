#include<iostream>
#include"sparta.h"
#include"workManager.h"
using namespace std;

Sparta::Sparta(string CharacterName, int CharacterLifeValue, int WeightValue) {

	this->m_CharacterLifeValue = CharacterLifeValue;
	this->m_CharacterName = CharacterName;
	this->m_WeightValue = WeightValue;
}

void Sparta::showInformation() {
	cout << "name : " << this->m_CharacterName << endl;
	cout << "life : " << this->m_CharacterLifeValue << endl;
	cout << "weight : " << this->m_WeightValue << endl;
}