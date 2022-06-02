#include <iostream>
#include <string>
#include "Screen.h"
#include "Pay.h"
using namespace std;

Screen::Screen(string name, int price, int row, int col) {
	strMovieName = name;
	nRowMax = row;
	nColMax = col;
	nTicketPrice = price;
	pSeatArray = new Ticket * [nRowMax];
	nCurrentReservedId = 1;
	for (int r = 0; r < nRowMax; r++) {
		pSeatArray[r] = new Ticket[nColMax];
	}
	for (int i = 0; i < nRowMax; i++) {
		for (int j = 0; j < nColMax; j++) {
			pSeatArray[i][j].setCheck(SEAT_EMPTY_MARK);
		}
	}
}

Screen::~Screen() {}

void Screen::showMovieMenu() {
	cout << endl;
	cout << "----------------------------------------" << endl;
	cout << "      ��ȭ �޴� - " << strMovieName << endl;
	cout << "----------------------------------------" << endl;
	cout << "1. ��ȭ ����" << endl;
	cout << "2. ���� ��Ȳ" << endl;
	cout << "3. ���� �ϱ�" << endl;
	cout << "4. ���� ���" << endl;
	cout << "5. ���� �ϱ�" << endl;
	cout << "7. ���� �޴� �̵�" << endl;
	cout << endl;
}

void EuropeScreen::showMovieInfo(){
	cout << "----------------------------------------" << endl;
	cout << "      [ " << strMovieName << " ]" << endl;
	cout << "----------------------------------------" << endl;
	cout << "��ȭ�� : ������ȭ 1��" << endl;
	cout << "���ΰ�: �˷� ������, ������ ũ��������" << endl;
	cout << "�ٰŸ�: �Ϳ��� �ƱⰡ ��� '���̺� �ֽ�ȸ��'�� ī������ ����?!" << endl;
	cout << "        ����� ����� �ٽ� ��ã�� ���� ���� ���̺�� ���� ��, ���� ��ġ �ʴ� ������ ���۵ȴ�!" << endl;
	cout << "����: " << nTicketPrice << endl;
}

void AsiaScreen::showMovieInfo() {
	cout << "----------------------------------------" << endl;
	cout << "      [ " << strMovieName << " ]" << endl;
	cout << "----------------------------------------" << endl;
	cout << "��ȭ�� : �ƽþƿ�ȭ 2��" << endl;
	cout << "���ΰ�: ������, �ڼҴ�" << endl;
	cout << "�ٰŸ�: ���Ҵ� ������ ���� �ǹ��� ���� �ô޸��� �ҳฦ ���� ���� �� ���� ����..." << endl;
	cout << "        �ҳฦ ���ϱ� ���� ����� ����� ���� ���� �ִ� ������ ������ �����Ѵ�!" << endl;
	cout << "����: " << nTicketPrice << endl;
}

void PremiumScreen::showMovieInfo() {
	cout << "----------------------------------------" << endl;
	cout << "      [ " << strMovieName << " ]" << endl;
	cout << "----------------------------------------" << endl;
	cout << "��ȭ�� : �����̾���ȭ 3��" << endl;
	cout << "���ΰ�: �� �ؼ�����, �ι�Ʈ ��Ϸ�" << endl;
	cout << "�ٰŸ�: ���������� ȸ�縦 â���� �������� CEO�� �ٽ�!" << endl;
	cout << "        �̷� �ٽ� �տ� ���� �Ⱓ�� �����Ȱ�� ��ġ�� �� 70���� ������ �����ϴµ�..." << endl;
	cout << "����: " << nTicketPrice << endl;
}

void Screen::showSeatMap(){
	cout << "[ �¼� ���� ��Ȳ ]" << endl;
	cout << "\t[1]  ";
	for (int i = 1; i < nColMax; i++) {
		cout << "[" << i + 1 << "]  ";
	}
	cout << endl;
	for (int i = 0; i < nRowMax; i++) {
		cout << "[" << i + 1 << "]\t";
		for (int j = 0; j < nColMax; j++) {
			cout << "[" << pSeatArray[i][j].getCheck() << "]  ";
		}
		cout << endl;
	}
}

void Screen::reserveTicket() {
	int row;
	int col;
	int id = nCurrentReservedId;
	nCurrentReservedId++;

	cout << "  [ �¼� ���� ]" << endl;
	cout << "�¼� ���ȣ �Է�(1 - " << nRowMax << ") : ";
	cin >> row;
	cout << "�¼� ����ȣ �Է�(1 - " << nColMax << ") : ";
	cin >> col;

	pSeatArray[row - 1][col - 1].setSeat(row - 1, col - 1);
	pSeatArray[row - 1][col - 1].setReservedID(id);
	pSeatArray[row - 1][col - 1].setCheck(SEAT_RESERVED_MARK);

	cout << "�� [" << row << "] �� [" << col << "] " << id << " ���� ��ȣ�� �����Ǿ����ϴ�." << endl;
}

Ticket* Screen::checkReservedID(int id) {
	for (int i = 0; i < nRowMax; i++) {
		for (int j = 0; j < nColMax; j++) {
			if (pSeatArray[i][j].getCheck() != SEAT_EMPTY_MARK) {
				if (id == pSeatArray[i][j].getReservedID()) {
					pSeatArray[i][j].setPayAmount(nTicketPrice);
					return &pSeatArray[i][j];
				}
			}
		}
	}
	return NULL;
}

void Screen::cancelReservatoin() {
	int id;

	cout << "  [ �¼� ���� ��� ]" << endl;
	cout << "���� ��ȣ �Է� : ";
	cin >> id;

	Ticket* ticket = checkReservedID(id);

	if (ticket == NULL) {
		cout << "���� ��ȣ�� �������� �ʽ��ϴ�." << endl;
		return;
	}
	if (ticket->getCheck() == SEAT_COMPLETION_MARK) {
		cout << "�̹� ������ �¼��� ����� �� �����ϴ�." << endl;
		return;
	}
	ticket->setCheck(SEAT_EMPTY_MARK);
	ticket->setReservedID(0);

	cout << id << " ���� ��ȣ�� ��� ó���Ǿ����ϴ�." << endl;
}

void Screen::payment() {
	int id;
	int method;
	Pay* pay = NULL;
	int charge;

	cout << "  [ �¼� ���� ���� ]" << endl;
	cout << "���� ��ȣ �Է� : ";
	cin >> id;

	Ticket* ticket = checkReservedID(id);
	if (ticket == NULL) {
		cout << "���� ��ȣ�� �������� �ʽ��ϴ�." << endl;
		return;
	}
	cout << endl;
	cout << "----------------------------------------" << endl;
	cout << "      ���� ��� ����" << endl;
	cout << "----------------------------------------" << endl;
	cout << "1. ����� ����" << endl;
	cout << "2. ���� ��ü ����" << endl;
	cout << "3. ī�� ����" << endl;
	cout << endl << "���� ��� (1~3) : ";

	cin >> method;

	switch (method) {
	case 1:
		pay = new MobilePay(MOBILE_PHONE_INTEREST_RATE);
		break;
	case 2:
		pay = new BankTransfer(BANK_TRANSFER_INTEREST_RATE);
		break;
	case 3:
		pay = new CardPay(CREDIT_CARD_INTEREST_RATE);
		break;
	default:
		pay = NULL;
		break;
	}

	if (pay == NULL) {
		cout << "�߸� �����ϼ̽��ϴ�." << endl;
		return;
	}
	charge = pay->charge(ticket->getPayAmount());
	ticket->setPayAmount(charge);
	ticket->setCheck(SEAT_COMPLETION_MARK);
}