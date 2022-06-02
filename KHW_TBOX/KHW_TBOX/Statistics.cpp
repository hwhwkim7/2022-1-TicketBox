#include <iostream>
#include "Statistics.h"
using namespace std;

int Statistics::totalRevenue(Screen* pScreen){
	int sum = 0;

	Ticket** ticket = pScreen->getTicketArray();
	for (int i = 0; i < pScreen->getRowMax(); i++) {
		for (int j = 0; j < pScreen->getColMax(); j++) {
			if (ticket[i][j].getCheck() == SEAT_COMPLETION_MARK) {
				sum += ticket[i][j].getPayAmount();
			}
		}
	}
	return sum;
}

int Statistics::totalSalesCount(Screen* pScreen){
	int count = 0;

	Ticket** ticket = pScreen->getTicketArray();
	for (int i = 0; i < pScreen->getRowMax(); i++) {
		for (int j = 0; j < pScreen->getColMax(); j++) {
			if (ticket[i][j].getCheck() == SEAT_COMPLETION_MARK) {
				count++;
			}
		}
	}
	return count;
}
