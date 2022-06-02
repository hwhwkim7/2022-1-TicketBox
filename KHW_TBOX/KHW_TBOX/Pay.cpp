#include <iostream>
#include "Screen.h"
#include "Pay.h"
using namespace std;

int CardPay::charge(int amount){
	string phone;
	string name;

	cout << "      [ 신용카드 결제 ]" << endl;
	cout << "핸드폰 번호 입력(11자리 수) : ";
	cin >> phone;
	cout << "이름 : ";
	cin >> name;

	cout << "카드 결제가 완료되었습니다. : " << amount + amount * interest << endl;

	return amount + amount * interest;
}

int BankTransfer::charge(int amount){
	string phone;
	string name;

	cout << "      [ TUKOREA 은행 결제 ]" << endl;
	cout << "핸드폰 번호 입력(11자리 수) : ";
	cin >> phone;
	cout << "이름 : ";
	cin >> name;

	cout << "TUKOREA 은행 결제가 완료되었습니다. : " << amount + amount * interest << endl;

	return amount + amount * interest;
}

int MobilePay::charge(int amount){
	string phone;
	string name;

	cout << "      [ 모바일 결제 ]" << endl;
	cout << "핸드폰 번호 입력(11자리 수) : ";
	cin >> phone;
	cout << "이름 : ";
	cin >> name;

	cout << "모바일 결제가 완료되었습니다. : " << amount + amount * interest << endl;

	return amount + amount * interest;
}