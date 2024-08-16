#include<iostream>
#include"workManager.h"
#include"sword.h"
#include"sheid.h"
#include"knight.h"
#include"sparta.h"
#include"monster.h"
#include"character.h"
#include"gesra.h"
#include"hammer.h"
#include"arrow.h"
#include"bigkandao.h"
#include"criticalhit.h"
#include"flash.h"
using namespace std;
#include<random>;


WorkManager::WorkManager() {


	//ifstream ifs1;
	//ifs1.open(FILENAME1, ios::in);
	//char ch1;
	//ifs1 >> ch1;
	//if (ifs1.eof())
	//{
	//	this->m_weaponNum = 0;
	//	ifs1.close();
	//	return;
	//}


	//ifstream ifs2;
	//ifs2.open(FILENAME2, ios::in);

	//char ch2;
	//ifs2 >> ch2;
	//if (ifs2.eof())
	//{
	//	this->m_weaponNum = 0;
	//	ifs2.close();
	//	return;
	//}
	//ifs1.close();
	//ifs2.close();
	this->m_weaponNum = this->getWeaponNum();
	this->m_WeaponArray = new WeaponAndEquipment * [m_weaponNum];
	this->m_characterNum = this->getCharacterNum();
	this->m_CharacterArray = new Character * [m_characterNum];
	this->init_weaponArray();
	this->init_characterArray();

	this->m_attributeNum = this->getAttributeNum();
	this->m_AttributeArray = new Attribute * [m_attributeNum];
	this->init_attributeArray();
}

void WorkManager::init_attributeArray()
{
	ifstream ifs;
	ifs.open(FILENAME3, ios::in);
	int attribute_id;
	string name;
	double critical_hit_damage;
	int index = 0;
	while (ifs >> attribute_id && ifs >> name && ifs >> critical_hit_damage)
	{
		Attribute* attribute = NULL;
		switch (attribute_id)
		{
		case 1:
			attribute = new Criticalhit(attribute_id, name, critical_hit_damage);
			break;
		default:
			break;
		}
		this->m_AttributeArray[index++] = attribute;
	}
	ifs.close();
	
}

void WorkManager::init_characterArray()
{
	ifstream ifs;
	ifs.open(FILENAME1, ios::in);
	string name;
	int lifeValue;
	int weightValue;
	int index = 0;
	while (ifs >> name && ifs >> lifeValue && ifs >> weightValue)
	{
		Character* character = NULL;
		if (name == "knight")
		{
			character = new Knight(name, lifeValue, weightValue);
		}
		else if (name == "sparta")
		{
			character = new Sparta(name, lifeValue, weightValue);


			this->m_CharacterArray[index++] = character;
		}
		ifs.close();
	}
}

void WorkManager::init_weaponArray()
{
	ifstream ifs;
	ifs.open(FILENAME2, ios::in);

	int init_weapon_id;
	string init_name;
	int equipmentDamage;
	int equipmentWeight;
	int equipmentDefense;
	int index = 0;
	while (ifs >> init_weapon_id && ifs >> init_name && ifs >> equipmentDamage && ifs >> equipmentWeight && ifs >> equipmentDefense)
	{
		WeaponAndEquipment* weapon = NULL;
		switch (init_weapon_id)
		{
		case 1:
			weapon = new Sword(init_weapon_id, init_name, equipmentDamage, equipmentWeight, equipmentDefense);
			break;
		case 2:
			weapon = new Sheid(init_weapon_id, init_name, equipmentDamage, equipmentWeight, equipmentDefense);
			break;
		case 3:
			weapon = new Hammer(init_weapon_id, init_name, equipmentDamage, equipmentWeight, equipmentDefense);
			break;
		case 4:
			weapon = new Arrow(init_weapon_id, init_name, equipmentDamage, equipmentWeight, equipmentDefense);
			break;
		case 5:
			weapon = new Bigkandao(init_weapon_id, init_name, equipmentDamage, equipmentWeight, equipmentDefense);
			break;
		default:
			break;
		}
		this->m_WeaponArray[index++] = weapon;
	}
	ifs.close();

}

void WorkManager::showMenu() {
	cout << "***********************************" << endl;
	cout << "************   ��ӭ  **************" << endl;
	cout << "************ 1.��ʼ **************" << endl;
	cout << "************ 2.�鿴�淨 ***" << endl;
	cout << "************ 3.�˳� **********" << endl;
	cout << "***********************************" << endl;
	cout << "***********************************" << endl;

}

void WorkManager::actionMenu()
{
	cout << "***********************************" << endl;
	cout << "***** ��ѡ������ж� ***" << endl;
	cout << "*********** 1.������ ****************" << endl;
	cout << "*********** 2.�������� *********" << endl;
	cout << "*********** 3.�鿴��ɫ ******" << endl;
	cout << "*********** 4.�鿴���� ******" << endl;
	cout << "*********** 5.�˳� ***********" << endl;
	cout << "***********************************" << endl;
	cout << "***********************************" << endl;
}



void WorkManager::beatMonsterGesra()
{
	if (!haveWeapon())
	{
		return;
	}



	Gesra* gesra = nullptr;

	gesra = new Gesra("gesra",  20,5);

	cout << "waiting ... ... " << endl;

	while (this->m_CharacterArray[0]->m_CharacterLifeValue > 0 && gesra->m_MonsterLifeValue > 0)
	{
		int choose_num;
		int   weapon_id;
		string character_name;

		system("cls");

		cout << "��ѡ����Ĳ����� : " << endl;
		cout << "1. ���Ǹ� !" << endl;
		cout << "2. �л�������" << endl;
		cout << "3. �л�����ɫ" << endl;
		cout << "4. �˳� " << endl;
		cin >> choose_num;
		switch (choose_num)
		{
		case 1:
			system("cls");
			beatMonster(gesra);
			break;
		case 2:
			cout << "***********************************" << endl;
			cout << "��ѡ������ʹ�õ������� !" << endl;
			this->showWeaponMenu();
			cin >> weapon_id;
			exchange_weapon(weapon_id);
			break;
		case 3:
			cout << "***********************************" << endl;
			cout << "��ѡ������ʹ�õ�����ɫ������ ��" << endl;
			this->showCharacterMenu();
			cin >> character_name;
			exchange_character(character_name);
			break;
		case 4:
			this->exitGame();
			break;

		default:
			break;
		}
		


	}
	if (this->m_CharacterArray[0]->m_CharacterLifeValue > 0)
	{
		cout << "***********************************" << endl;
		cout << "��ʤ���� !" << endl;
	}
	else
	{
		cout << "***********************************" << endl;
		cout << "���� loser !" << endl;
		this->m_CharacterArray[0]->m_CharacterLifeValue = 0;
		this->m_CharacterArray[0]->m_CharacterName = "loser";
		delete[] this->m_WeaponArray;
		this->m_WeaponArray = NULL;
		this->exitGame();
		
	}
	this->saveCharacterFile();
	
}

void WorkManager::addCharacter() {
	while (true)
	{

		cout << "***********************************" << endl;
		cout << "******** ��ѡ����Ľ�ɫ ****" << endl;
		cout << "************ knight ***************" << endl;
		cout << "************ sparta ***************" << endl;
		cout << "***********************************" << endl;


		string c_name;

		bool sameCharacter = false;

		int new_character_num = this->m_characterNum + 1;

		cin >> c_name;
		Character** newSpace = new Character * [new_character_num];
		if (this->m_CharacterArray != NULL)
		{
			for (int i = 0; i < this->m_characterNum; i++)
			{
				newSpace[i] = this->m_CharacterArray[i];
			}

		}
		Character* character = nullptr;
		if (c_name == "knight")
		{
			for (int j = 0; j < this->m_characterNum; j++)
			{

				if (c_name == this->m_CharacterArray[j]->m_CharacterName)
				{
					cout << "***********************************" << endl;
					cout << "���ʧ�ܣ���Ϊ���Ѿ���һ��С��ʿ�� !" << endl;
					sameCharacter = true;
					break;
				}
			}
			if (sameCharacter)
			{
				continue;
			}
			character = new Knight("knight", 20, 10);
			cout << "***********************************" << endl;
			cout << "С��ʿ��������Ķ��� !" << endl;
			
		}
		else if (c_name == "sparta")
		{
			for (int j = 0; j < this->m_characterNum; j++)
			{

				if (c_name == this->m_CharacterArray[j]->m_CharacterName)
				{
					cout << "*******************************" << endl;
					cout << "���ʧ�ܣ���Ϊ���Ѿ���һ��˹�ʹ���ʿ�� ! " << endl;
					sameCharacter = true;
					break;
				}
			}
			if (sameCharacter)
			{
				continue;
			}
			character = new Sparta("sparta", 25, 8);
			cout << "*******************************" << endl;
			cout << "˹�ʹ�������ʿ�е�����һ���������� ! " << endl;
		}
		else
		{
			cout << "�������Ӣ����������û���κ��˼�������Ķ��飬�����԰� ��" << endl;
			continue;
		}

		newSpace[this->m_characterNum] = character;

		delete[] this->m_CharacterArray;

		this->m_CharacterArray = newSpace;
		this->m_characterNum = new_character_num;
		this->saveCharacterFile();
		break;
	}

}

void WorkManager::addAttribute()
{
	cout << "ѡ���������" << endl;
	cout << "1.��ɫ��Ƭ" << endl;
	cout << "2.��ɫ��Ƭ" << endl;
	int attribute_id;
	cin >> attribute_id;

	for (int i = 0; i < this->m_attributeNum; i++)
	{
		if (this->m_AttributeArray[i]->m_attribute_id == attribute_id)
		{
			switch (attribute_id)
			{
			case 1:
				this->m_AttributeArray[i]->m_CriticalHitDamage += 10;
				break;
			case 2:
				this->m_AttributeArray[i]->m_flash_damage += 2;
				break;
			default:
				break;
			}
			this->saveAttribute();
			return;
		}
	}

	int newSize = this->m_attributeNum + 1;
	Attribute** newSpace = new Attribute * [newSize];



	if (this->m_AttributeArray != NULL)
	{

		for (int i = 0; i < this->m_attributeNum; i++)
		{
			newSpace[i] = this->m_AttributeArray[i];
		}
	}

	Attribute* attribute = nullptr;
	switch (attribute_id)
	{
	case 1:
		attribute = new Criticalhit(1, "criticalhit", 10);
		break;
	case 2:
		attribute = new Flash(2, "flash", 2);
		break;
	default:
		break;
	}
	newSpace[this->m_attributeNum] = attribute;

	delete[] this->m_AttributeArray;
	this->m_AttributeArray = newSpace;
	this->m_attributeNum = newSize;
	this->saveAttribute();
	
}

void WorkManager::addWeapon() 
{
	int random_num;
	while (true)
	{
		cout << "*******************************" << endl;
		cout << "***** ����һ��ѡ�����Ļ��ᣡ ******" << endl;
		cout << "***** ��ѡ��������� ******" << endl;
		cout << "******** 1.ʥ�� *********" << endl;
		cout << "******** 2.���� *********" << endl;
		cout << "******** 3.�������������ܻ����ظ��ģ� ********" << endl;
		cout << "******** 4.���� **********" << endl;
		cout << "*******************************" << endl;
		int w_num;

		bool sameWeapon = false;

		int new_weapon_num = this->m_weaponNum + 1;

		cin >> w_num;
		WeaponAndEquipment** newSpace = new WeaponAndEquipment * [new_weapon_num];
		if (this->m_WeaponArray != NULL)
		{
			for (int i = 0; i < this->m_weaponNum; i++)
			{
				newSpace[i] = this->m_WeaponArray[i];
			}

		}

		WeaponAndEquipment* weapon = nullptr;
		switch (w_num)
		{
		case 1:
			for (int j = 0; j < this->m_weaponNum; j++)
			{

				if (w_num == this->m_WeaponArray[j]->m_weapon_id)
				{
					cout << "*******************************" << endl;
					cout << "���ʧ�ܣ����Ѿ������������ ! " << endl;
					sameWeapon = true;
					break;
				}
			}
			if (sameWeapon)
			{
				continue;
			}
			if (this->verify_weight(3))
			{
				weapon = new Sword(1, "sword", 4, 2, 2);
				this->m_CharacterArray[0]->m_WeightValue -= 2;
				cout << "*******************************" << endl;
				cout << "������ �� ʥ�� !" << endl;
				break;
			}
			else
			{
				cout << "���޷�������������ˣ���Ϊ�㲻��ǿ�� !" << endl;
				continue;
			}
			
		case 2:
			for (int j = 0; j < this->m_weaponNum; j++)
			{

				if (w_num == this->m_WeaponArray[j]->m_weapon_id)
				{
					cout << "*******************************" << endl;
					cout << "���ʧ�ܣ����Ѿ������������ ! " << endl;
					sameWeapon = true;
					continue;
				}
			}
			if (sameWeapon)
			{
				continue;
			}
			if (this->verify_weight(3))
			{
				weapon = new Sheid(2, "sheid", 1, 2, 6);
				this->m_CharacterArray[0]->m_WeightValue -= 2;
				cout << "*******************************" << endl;
				cout << "������ �� ����  !" << endl;
				break;
			}
			else
			{
				cout << "�����������Ѿ������˼��ޣ������������������⽫����ѹ�����յ����һ������ !" << endl;
				continue;
			}
		case 3:

			random_num = getRandomNum();
			weapon = addAnyweapon(random_num,weapon);
			if (weapon == nullptr)
			{
				return;
			}
			break;
		case 4:
			return;
		default:
			break;
		}

		newSpace[this->m_weaponNum] = weapon;

		delete[] this->m_WeaponArray;

		this->m_WeaponArray = newSpace;
		this->m_weaponNum = new_weapon_num;
		this->saveWeaponFile();
		break;
	}
	

}

WeaponAndEquipment* WorkManager::addAnyweapon(int weapon_id, WeaponAndEquipment* weapon)
{
		
		switch (weapon_id)
		{
		case 3:
			for (int j = 0; j < this->m_weaponNum; j++)
			{

				if (weapon_id == this->m_WeaponArray[j]->m_weapon_id)
				{
					cout << "*******************************" << endl;
					cout << "������ �� ʯ���� !" << endl;
					cout << "����....���ʧ�� , �㲻�ܻ����ͬ������ ! " << endl;
					cout << "��������λ��� " << endl;
					return nullptr;
				}
			}
			if (this->verify_weight(3))
			{
				weapon = new Hammer(3, "hammer", 6, 3, 1);
				this->m_CharacterArray[0]->m_WeightValue -= 3;
				cout << "*******************************" << endl;
				cout << "�����ˣ�ʯ�� !" << endl;
				return weapon;
			}
			else
			{
				cout << "�����ˣ�ʯ�� ! !" << endl;
				cout << "����....���ʧ�� , �������� !" << endl;
				cout << "��������λ��� !" << endl;
				return nullptr;
			}
		case 4:
			for (int j = 0; j < this->m_weaponNum; j++)
			{

				if (weapon_id == this->m_WeaponArray[j]->m_weapon_id)
				{
					cout << "*******************************" << endl;
					cout << "������ �� ���� !" << endl;
					cout << "����....���ʧ�� , �㲻�ܻ����ͬ������ ! " << endl;
					cout << "��������λ��� " << endl;
					return nullptr;
				}
			}
			if (this->verify_weight(1))
			{
				weapon = new Arrow(4, "arrow", 5, 1, 0);
				this->m_CharacterArray[0]->m_WeightValue -= 1;
				cout << "*******************************" << endl;
				cout << "�����ˣ����� !" << endl;
				return weapon;
			}
			else
			{
				cout << "�����ˣ����� ! !" << endl;
				cout << "����....���ʧ�� , �������� !" << endl;
				cout << "��������λ��� !" << endl;
				return nullptr;
			}
		case 5:
			for (int j = 0; j < this->m_weaponNum; j++)
			{

				if (weapon_id == this->m_WeaponArray[j]->m_weapon_id)
				{
					cout << "*******************************" << endl;
					cout << "������ �� �󿳵��� !" << endl;
					cout << "����....���ʧ�� , �㲻�ܻ����ͬ������ ! " << endl;
					cout << "��������λ��� " << endl;
					return nullptr;
				}
			}
			if (this->verify_weight(2))
			{
				weapon = new Bigkandao(5, "bigkandao", 5, 2, 2);
				this->m_CharacterArray[0]->m_WeightValue -= 2;
				cout << "*******************************" << endl;
				cout << "�����ˣ��󿳵� !" << endl;
				return weapon;
			}
			else
			{
				cout << "�����ˣ��󿳵� ! !" << endl;
				cout << "����....���ʧ�� , �������� !" << endl;
				cout << "��������λ��� !" << endl;
				return nullptr;
			}
		case 6:
			for (int j = 0; j < this->m_weaponNum; j++)
			{

				if (weapon_id == this->m_WeaponArray[j]->m_weapon_id)
				{
					cout << "*******************************" << endl;
					cout << "������ �� С�ݣ� !" << endl;
					cout << "����....���ʧ�� , �㲻�ܻ����ͬ������ ! " << endl;
					cout << "��������λ��� " << endl;
					return nullptr;
				}
			}
			if (this->verify_weight(0))
			{
				weapon = new Bigkandao(6, "smallgrass", 0, 0, 0);
				this->m_CharacterArray[0]->m_WeightValue -= 0;
				cout << "*******************************" << endl;
				cout << "�����ˣ�С�� !" << endl;
				cout << "��û���κ��� ��" << endl;
				return weapon;
			}
			else
			{
				cout << "�����ˣ�С�� ! !" << endl;
				cout << "����....���ʧ�� , �������� !" << endl;
				cout << "��������λ��� !" << endl;
				return nullptr;
			}
		case 7:
			for (int j = 0; j < this->m_weaponNum; j++)
			{

				if (weapon_id == this->m_WeaponArray[j]->m_weapon_id)
				{
					cout << "*******************************" << endl;
					cout << "������ �� �������� !" << endl;
					cout << "����....���ʧ�� , �㲻�ܻ����ͬ������ ! " << endl;
					cout << "��������λ��� " << endl;
					return nullptr;
				}
			}
			if (this->verify_weight(4))
			{
				weapon = new Bigkandao(7, "wolfteethbang", 6, 4, 3);
				this->m_CharacterArray[0]->m_WeightValue -= 4;
				cout << "*******************************" << endl;
				cout << "�����ˣ������� !" << endl;
				return weapon;
			}
			else
			{
				cout << "�����ˣ������� ! !" << endl;
				cout << "����....���ʧ�� , �������� !" << endl;
				cout << "��������λ��� !" << endl;
				return nullptr;
			}
		default:
			cout << "���������ǵĹ��裡���ͣ�Ҫ���Ź⣡" << endl;
			return nullptr;
			break;
		}
	
}

void WorkManager::beatMonster(Monster *monster)
{
	int character_damage;
	int monster_damage;
	int round_num = 0;
	double Damage_multiple=1;
	double Damage_plus=0;
	if (this->m_attributeNum > 0)
	{
		for (int i = 0; i < this->m_attributeNum; i++)
		{
			switch (this->m_AttributeArray[i]->m_attribute_id)
			{
			case 1:
				Damage_multiple = this->ifCritiacl(this->m_AttributeArray[i]->m_CriticalHitDamage);
				
				break;
			case 2:
				Damage_plus = this->m_AttributeArray[i]->m_flash_damage;
				break;
			default:
				Damage_multiple = 1;
				Damage_plus = 0;
				break;
			}
		}
	}
	character_damage = this->m_WeaponArray[0]->m_equipmentDamage * Damage_multiple + Damage_plus;
	monster_damage = monster->m_MonsterDamage - this->m_WeaponArray[0]->m_equipmentDefense;
	cout << "********************" << endl;
	cout << "round " << round_num << endl;
	if (monster_damage < 0)
	{
		monster_damage = 0;
		cout << "������������ֵ���ߣ������˺����ߣ�" << endl;
	}
	monster->m_MonsterLifeValue -= character_damage;
	this->m_CharacterArray[0]->m_CharacterLifeValue -= monster_damage;

	cout << "********************" << endl;
	cout << "��������ֵ : " << monster->m_MonsterLifeValue << endl;
	cout << "�������ֵ : " << this->m_CharacterArray[0]->m_CharacterLifeValue << endl;
	system("pause");
	round_num++;
	return;
}


void WorkManager::exchange_weapon(int weapon_id)
{


	if (this->m_weaponNum == 1)
	{
		cout << "********************" << endl;
		cout << "��ǰֻ��һ������ ! " << endl;
		system("pause");

		return;
	}

	
	if (weapon_id == m_WeaponArray[0]->m_weapon_id)
	{
		cout << "********************" << endl;
		cout << "���Ѿ�������������� ! " << endl;
		return;
	}
	else
	{
		for (int j = 0; j < this->m_weaponNum; j++)
		{

			if (weapon_id == this->m_WeaponArray[j]->m_weapon_id)
			{
				WeaponAndEquipment* weapon = NULL;
				weapon = this->m_WeaponArray[j];
				this->m_WeaponArray[j] = this->m_WeaponArray[0];
				this->m_WeaponArray[0] = weapon;
			}
		}
		cout << "********************" << endl;
		cout << " �л��������ɹ� !" << endl;
	}
}

void WorkManager::exchange_character(string name)
{
	

	if (this->m_characterNum == 1)
	{
		cout << "********************" << endl;
		cout << "��ֻ��һ����ɫ ! " << endl;
		system("pause");

		return;
	}

	
	if (name ==this->m_CharacterArray[0]->m_CharacterName)
	{
		cout << "********************" << endl;
		cout << "�������ɫ�Ѿ������� ! " << endl;
		return;
	}
	else
	{
		for (int j = 0; j < this->m_characterNum; j++)
		{

			if (name == this->m_CharacterArray[j]->m_CharacterName)
			{
				Character* character = NULL;
				character = this->m_CharacterArray[j];
				this->m_CharacterArray[j] = this->m_CharacterArray[0];
				this->m_CharacterArray[0] = character;
			}
		}
		cout << "********************" << endl;
		cout << " �л��ɹ� !" << endl;
		system("pause");
	}
}

void WorkManager::showCharacterMenu() {
	cout << "*******************************" << endl;
	cout << "�������� " << this->m_characterNum << " ����ɫ " << endl;
	for (int i = 0; i < this->m_characterNum; i++)
	{
		this->m_CharacterArray[i]->showInformation();
	}
	system("pause");
	system("cls");
}

void WorkManager::showWeaponMenu() {
	cout << "*******************************" << endl;
	cout << "�������� " << this->m_weaponNum << " ������" << endl;
	for (int i = 0; i < this->m_weaponNum; i++)
	{
		this->m_WeaponArray[i]->showInformation();
	}
	system("pause");
	system("cls");
}

void WorkManager::showAttributeMenu() {
	cout << "*******************************" << endl;
	cout << "�������� " << this->m_weaponNum << " ������" << endl;
	for (int i = 0; i < this->m_attributeNum; i++)
	{
		this->m_AttributeArray[i]->showInformation();
	}
	system("pause");
	system("cls");
}

void WorkManager::showGameRule() 
{
	cout << "ѡ����������ͽ�ɫȥ���ܹ��޲�ͨ�� !" << endl;
}

void WorkManager::saveAttribute()
{
	ofstream ofs;
	ofs.open(FILENAME3, ios::out);
	for (int i = 0; i < this->m_attributeNum; i++)
	{
		ofs << "attribute id : " << this->m_AttributeArray[i]->m_attribute_id << " "
			<< "attribute name : " << this->m_AttributeArray[i]->m_AttributeName << endl;

	}
	ofs.close();
}


void WorkManager::saveCharacterFile()
{
	ofstream ofs;
	ofs.open(FILENAME1, ios::out);

	for (int i = 0; i < this->m_characterNum; i++)
	{
		ofs << " name  : " << this->m_CharacterArray[i]->m_CharacterName << " "
			<< " life value : " << this->m_CharacterArray[i]->m_CharacterLifeValue << " "
			<< " weight value : " << this->m_CharacterArray[i]->m_WeightValue << endl;
	}

	ofs.close();
}

void WorkManager::saveWeaponFile()
{
	ofstream ofs;
	ofs.open(FILENAME2, ios::out);
	for (int i = 0; i < this->m_weaponNum; i++)
	{
		ofs << " weapon id : " << this->m_WeaponArray[i]->m_weapon_id << " "
			<< " weapon name : " << this->m_WeaponArray[i]->m_name << " "
			<< " weapon damage : " << this->m_WeaponArray[i]->m_equipmentDamage << " "
			<< " weapon defense : " << this->m_WeaponArray[i]->m_equipmentDefense << " "
			<< " weapon weight : " << this->m_WeaponArray[i]->m_equipmentWeight << endl;
		
	}
	ofs.close();
}

int WorkManager::getAttributeNum()
{
	ifstream ifs;
	ifs.open(FILENAME3, ios::in);

	int attribute_num = 0;

	int attribute_id;
	string name;
	double critical_hit_damage;

	while (ifs >> attribute_id && ifs >> name && ifs >> critical_hit_damage)
	{
		attribute_num++;
	}
	ifs.close();
	return attribute_num;
}

int WorkManager::getWeaponNum()
{
	ifstream ifs;
	ifs.open(FILENAME2, ios::in);
	
	int weapon_num = 0;

	int weapon_id;
	string name;
	int equipmentDamage;
	int equipmentWeight;
	int equipmentDefense;
	while (ifs >> weapon_id &&ifs >> name && ifs >> equipmentDamage && ifs >> equipmentWeight && ifs >> equipmentDefense)
	{
		weapon_num++;
	}
	ifs.close();
	return weapon_num;
}

int WorkManager::getCharacterNum()
{
	ifstream ifs;
	ifs.open(FILENAME1, ios::in);

	int character_num = 0;

	string name;
	int lifeValue;
	while (ifs >> name && ifs >> lifeValue )
	{
		character_num++;
	}
	ifs.close();
	return character_num;
}

void WorkManager::exitGame() 
{
	cout << "*******************************" << endl;
	cout << "��ӭ�´������� !" << endl;
	system("pause");
	exit(0);
}

bool WorkManager::verify_weight(int weight)
{
	if (this->m_CharacterArray[0]->m_WeightValue - weight < 0)
	{
		return false;
	}
	return true;
}

bool WorkManager::haveWeapon()
{
	if (this->m_weaponNum == 0)
	{
		cout << "���ֿ�ȭ��սʤ����ǿ��ĵ��˵� �� �����ˣ�" << endl;
		this->exitGame();
		return false;
	}
	return true;
}

int WorkManager::getRandomNum()
{
	random_device rd; // ʹ��Ӳ���������������
	mt19937 gen(rd()); // ʹ�� Mersenne Twister ����
	uniform_int_distribution<int> dis(3, 10); // ������ȷֲ�

	int random_number = dis(gen); // ���������


	return random_number;
}

int  WorkManager::ifCritiacl(int rate)
{
	random_device rd; // ���������
	mt19937 gen(rd()); // Mersenne Twister ����
	uniform_int_distribution<int> dis(0, 100); // ���ȷֲ��� [0.0, 1.0] �����ڵ������������

	int random_number = dis(gen); // ����һ�������

	if (random_number < rate) { // ��������С�ڸ�����ֵ�������˺�����
		cout << this->m_CharacterArray[0]->m_CharacterName << "����˱�����" << endl;
		return 2;
	}
	else {
		return 1;
	}
}

WorkManager :: ~WorkManager()
{
	if (this->m_WeaponArray != NULL)
	{
		delete[] this->m_WeaponArray;
		this->m_WeaponArray = NULL;
	}

	if (this->m_CharacterArray != NULL)
	{
		delete this->m_CharacterArray;
		this->m_CharacterArray = NULL;
	}
	if (this->m_AttributeArray != NULL)
	{
		delete this->m_AttributeArray;
		this->m_AttributeArray = NULL;
	}

}