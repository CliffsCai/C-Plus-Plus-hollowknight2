#include<iostream>
#include"knight.h"
#include"workManager.h"
using namespace std;

Knight::Knight(string CharacterName, int CharacterLifeValue, int WeightValue) {

	this->m_CharacterLifeValue = CharacterLifeValue;
	this->m_CharacterName = CharacterName;
	this->m_WeightValue = WeightValue;

}

void Knight::showInformation() {
	cout << "name : " << this->m_CharacterName << endl;
	cout << "life : " << this->m_CharacterLifeValue << endl;
	cout << "weight : " << this->m_WeightValue << endl;
}