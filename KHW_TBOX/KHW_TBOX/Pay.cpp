#include <iostream>
#include "Screen.h"
#include "Pay.h"
using namespace std;

int CardPay::charge(int amount){
	string phone;
	string name;

	cout << "      [ �ſ�ī�� ���� ]" << endl;
	cout << "�ڵ��� ��ȣ �Է�(11�ڸ� ��) : ";
	cin >> phone;
	cout << "�̸� : ";
	cin >> name;

	cout << "ī�� ������ �Ϸ�Ǿ����ϴ�. : " << amount + amount * interest << endl;

	return amount + amount * interest;
}

int BankTransfer::charge(int amount){
	string phone;
	string name;

	cout << "      [ TUKOREA ���� ���� ]" << endl;
	cout << "�ڵ��� ��ȣ �Է�(11�ڸ� ��) : ";
	cin >> phone;
	cout << "�̸� : ";
	cin >> name;

	cout << "TUKOREA ���� ������ �Ϸ�Ǿ����ϴ�. : " << amount + amount * interest << endl;

	return amount + amount * interest;
}

int MobilePay::charge(int amount){
	string phone;
	string name;

	cout << "      [ ����� ���� ]" << endl;
	cout << "�ڵ��� ��ȣ �Է�(11�ڸ� ��) : ";
	cin >> phone;
	cout << "�̸� : ";
	cin >> name;

	cout << "����� ������ �Ϸ�Ǿ����ϴ�. : " << amount + amount * interest << endl;

	return amount + amount * interest;
}