#include <iostream>
#include "Screen.h"
#include "TicketBox.h"
#include "Statistics.h"
using namespace std;

TUKoreaTBox::~TUKoreaTBox(){}

void TUKoreaTBox::Initialize() {
	// Screen(��ȭ����, Ƽ�ϰ���, �¼�(nRowMax), �¼�(nColMax))
	pEuropeScreen = new EuropeScreen("���� ���̺�", 10000, 10, 10);
	pAsiaScreen = new AsiaScreen("���� ������", 12000, 10, 10);
	pPremiumScreen = new PremiumScreen("����", 30000, 6, 6);
}

void TUKoreaTBox::Manage() {
	string password;
	int count = Statistics::totalSalesCount(pEuropeScreen) + Statistics::totalSalesCount(pAsiaScreen) + Statistics::totalSalesCount(pPremiumScreen);

	cout << endl;
	cout << "---------------------------" << endl;
	cout << "     ������ �޴�" << endl;
	cout << "---------------------------" << endl;
	cout << "������ ��й�ȣ �Է� : ";
	cin >> password;
	if (password != TICKETBOX_MANAGER_PWD) {
		cout << "��й�ȣ�� Ʋ�Ƚ��ϴ�." << endl;
	}
	else {
		cout << endl;
		cout << "1. ������ȭ �󿵰� �����ݾ� : " << Statistics::totalRevenue(pEuropeScreen) << endl;
		cout << "2. �ƽþƿ�ȭ �󿵰� �����ݾ� : " << Statistics::totalRevenue(pAsiaScreen) << endl;
		cout << "3. �����̾���ȭ �󿵰� �����ݾ� : " << Statistics::totalRevenue(pPremiumScreen) << endl;
		cout << "4. ��ü Ƽ�� �Ǹŷ� : " << count << endl;
	}
}

Screen* TUKoreaTBox::selectMenu() {
	cout << endl;
	cout << "---------------------------" << endl;
	cout << "     �󿵰� ���� �޴�" << endl;
	cout << "---------------------------" << endl;
	cout << "1.   ����   ��ȭ 1��" << endl;
	cout << "2.  �ƽþ�  ��ȭ 2��" << endl;
	cout << "3. �����̾� ��ȭ 3��" << endl;
	cout << "9.   ���   ����" << endl;
	cout << endl;
	cout << "����(1~3,9) �׿� ���� : ";

	int select;
	cin >> select;
	Screen* screen = NULL;

	switch (select) {
	case 1:
		screen = pEuropeScreen;
		break;
	case 2:
		screen = pAsiaScreen;
		break;
	case 3:
		screen = pPremiumScreen;
		break;
	case 9:
		Manage();
 		break;
	default:
		screen = NULL;
		break;
	}

	return screen;
}