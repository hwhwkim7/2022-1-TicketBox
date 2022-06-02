#ifndef SCREEN_H
#define SCREEN_H
#include <string>
#include "Ticket.h"
using namespace std;

class Screen {
protected:
	int nTicketPrice; // Ƽ�� ����
	int nRowMax, nColMax; // �¼� ��� �� �ִ� ��
	int nCurrentReservedId; // �߱޵� ������ ���� ��ȣ
	Ticket** pSeatArray; // ��ũ�� �¼��� ���� Ƽ�� �迭
	string strMovieName; // ��ũ�� ������ ��ȭ ����
	Ticket* checkReservedID(int id); // ���� ��ȣ Ȯ��
public:
	Screen(string name, int price, int row, int col);
	~Screen();
	void showSeatMap(); // �¼� ���� ���� ������ ����
	virtual void showMovieMenu(); // ��ȭ ���� �޴�
	virtual void showMovieInfo() = 0; // ��ȭ �Ұ� ����
	void reserveTicket(); // �¼� �����ϱ�
	void cancelReservatoin(); // �¼� ���� ����ϱ�
	int getTicketPrice() { return nTicketPrice; }
	void payment(); // �����ϱ�
	int getRowMax() { return nRowMax; }
	int getColMax() { return nColMax; }
	Ticket** getTicketArray() { return pSeatArray; }
};

class EuropeScreen : public Screen {
public:
	EuropeScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {}
	void showMovieInfo();
};

class AsiaScreen : public Screen {
public:
	AsiaScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {}
	void showMovieInfo();
};

class PremiumScreen : public Screen {
public:
	PremiumScreen(string name, int price, int row, int col) : Screen(name, price, row, col) {}
	void showMovieInfo();
};
#endif