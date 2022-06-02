#include <iostream>
#include "Screen.h"
#include "TicketBox.h"
#include "Statistics.h"
using namespace std;

TUKoreaTBox::~TUKoreaTBox(){}

void TUKoreaTBox::Initialize() {
	// Screen(영화제목, 티켓가격, 좌석(nRowMax), 좌석(nColMax))
	pEuropeScreen = new EuropeScreen("보스 베이비", 10000, 10, 10);
	pAsiaScreen = new AsiaScreen("검은 사제들", 12000, 10, 10);
	pPremiumScreen = new PremiumScreen("인턴", 30000, 6, 6);
}

void TUKoreaTBox::Manage() {
	string password;
	int count = Statistics::totalSalesCount(pEuropeScreen) + Statistics::totalSalesCount(pAsiaScreen) + Statistics::totalSalesCount(pPremiumScreen);

	cout << endl;
	cout << "---------------------------" << endl;
	cout << "     관리자 메뉴" << endl;
	cout << "---------------------------" << endl;
	cout << "관리자 비밀번호 입력 : ";
	cin >> password;
	if (password != TICKETBOX_MANAGER_PWD) {
		cout << "비밀번호가 틀렸습니다." << endl;
	}
	else {
		cout << endl;
		cout << "1. 유럽영화 상영관 결제금액 : " << Statistics::totalRevenue(pEuropeScreen) << endl;
		cout << "2. 아시아영화 상영관 결제금액 : " << Statistics::totalRevenue(pAsiaScreen) << endl;
		cout << "3. 프리미엄영화 상영관 결제금액 : " << Statistics::totalRevenue(pPremiumScreen) << endl;
		cout << "4. 전체 티켓 판매량 : " << count << endl;
	}
}

Screen* TUKoreaTBox::selectMenu() {
	cout << endl;
	cout << "---------------------------" << endl;
	cout << "     상영관 메인 메뉴" << endl;
	cout << "---------------------------" << endl;
	cout << "1.   유럽   영화 1관" << endl;
	cout << "2.  아시아  영화 2관" << endl;
	cout << "3. 프리미엄 영화 3관" << endl;
	cout << "9.   통계   관리" << endl;
	cout << endl;
	cout << "선택(1~3,9) 그외 종료 : ";

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