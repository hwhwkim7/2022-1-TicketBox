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
	cout << "      영화 메뉴 - " << strMovieName << endl;
	cout << "----------------------------------------" << endl;
	cout << "1. 영화 정보" << endl;
	cout << "2. 예약 현황" << endl;
	cout << "3. 예약 하기" << endl;
	cout << "4. 예약 취소" << endl;
	cout << "5. 결제 하기" << endl;
	cout << "7. 메인 메뉴 이동" << endl;
	cout << endl;
}

void EuropeScreen::showMovieInfo(){
	cout << "----------------------------------------" << endl;
	cout << "      [ " << strMovieName << " ]" << endl;
	cout << "----------------------------------------" << endl;
	cout << "영화관 : 유럽영화 1관" << endl;
	cout << "주인공: 알렉 볼드윈, 마일즈 크리스토퍼" << endl;
	cout << "줄거리: 귀여운 아기가 사실 '베이비 주식회사'의 카리스마 보스?!" << endl;
	cout << "        어른들의 사랑을 다시 되찾기 위한 보스 베이비와 그의 형, 팀의 원치 않는 공조가 시작된다!" << endl;
	cout << "가격: " << nTicketPrice << endl;
}

void AsiaScreen::showMovieInfo() {
	cout << "----------------------------------------" << endl;
	cout << "      [ " << strMovieName << " ]" << endl;
	cout << "----------------------------------------" << endl;
	cout << "영화관 : 아시아영화 2관" << endl;
	cout << "주인공: 강동원, 박소담" << endl;
	cout << "줄거리: 뺑소니 교통사고 이후 의문의 증상에 시달리는 소녀를 위해 모인 두 명의 사제..." << endl;
	cout << "        소녀를 구하기 위해 모두의 목숨을 잃을 수도 있는 위험한 예식을 시작한다!" << endl;
	cout << "가격: " << nTicketPrice << endl;
}

void PremiumScreen::showMovieInfo() {
	cout << "----------------------------------------" << endl;
	cout << "      [ " << strMovieName << " ]" << endl;
	cout << "----------------------------------------" << endl;
	cout << "영화관 : 프리미엄영화 3관" << endl;
	cout << "주인공: 앤 해서웨이, 로버트 드니로" << endl;
	cout << "줄거리: 성공적으로 회사를 창업한 열정적인 CEO인 줄스!" << endl;
	cout << "        이런 줄스 앞에 수십 년간의 직장생활을 마치고 온 70세의 인턴이 등장하는데..." << endl;
	cout << "가격: " << nTicketPrice << endl;
}

void Screen::showSeatMap(){
	cout << "[ 좌석 예약 현황 ]" << endl;
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

	cout << "  [ 좌석 예약 ]" << endl;
	cout << "좌석 행번호 입력(1 - " << nRowMax << ") : ";
	cin >> row;
	cout << "좌석 열번호 입력(1 - " << nColMax << ") : ";
	cin >> col;

	pSeatArray[row - 1][col - 1].setSeat(row - 1, col - 1);
	pSeatArray[row - 1][col - 1].setReservedID(id);
	pSeatArray[row - 1][col - 1].setCheck(SEAT_RESERVED_MARK);

	cout << "행 [" << row << "] 열 [" << col << "] " << id << " 예약 번호로 접수되었습니다." << endl;
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

	cout << "  [ 좌석 예약 취소 ]" << endl;
	cout << "예약 번호 입력 : ";
	cin >> id;

	Ticket* ticket = checkReservedID(id);

	if (ticket == NULL) {
		cout << "예약 번호가 존재하지 않습니다." << endl;
		return;
	}
	if (ticket->getCheck() == SEAT_COMPLETION_MARK) {
		cout << "이미 결제된 좌석은 취소할 수 없습니다." << endl;
		return;
	}
	ticket->setCheck(SEAT_EMPTY_MARK);
	ticket->setReservedID(0);

	cout << id << " 예약 번호가 취소 처리되었습니다." << endl;
}

void Screen::payment() {
	int id;
	int method;
	Pay* pay = NULL;
	int charge;

	cout << "  [ 좌석 예약 결제 ]" << endl;
	cout << "예약 번호 입력 : ";
	cin >> id;

	Ticket* ticket = checkReservedID(id);
	if (ticket == NULL) {
		cout << "예약 번호가 존재하지 않습니다." << endl;
		return;
	}
	cout << endl;
	cout << "----------------------------------------" << endl;
	cout << "      결제 방식 선택" << endl;
	cout << "----------------------------------------" << endl;
	cout << "1. 모바일 결제" << endl;
	cout << "2. 은행 이체 결제" << endl;
	cout << "3. 카드 결제" << endl;
	cout << endl << "결제 방식 (1~3) : ";

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
		cout << "잘못 선택하셨습니다." << endl;
		return;
	}
	charge = pay->charge(ticket->getPayAmount());
	ticket->setPayAmount(charge);
	ticket->setCheck(SEAT_COMPLETION_MARK);
}