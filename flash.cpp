#include<iostream>
#include"flash.h"
using namespace std;

Flash::Flash(int attribute_id, string AttributeName, int  flash_damage) {

	this->m_attribute_id = attribute_id;
	this->m_AttributeName = AttributeName;
	this->m_flash_damage = flash_damage;


}

void Flash::showInformation() {
	cout << "�������� : ������Ƭ " << endl;
	cout << "���� : �����˺�+" << this->m_flash_damage << " " << endl;
}