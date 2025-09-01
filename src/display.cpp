#include <iostream>
#include "utils.h"
#include "requests.h"
using namespace std;

extern vector<Request> finalizedRequests;
extern chrono::system_clock::time_point finalizedDate;

void displayInitialScreen() {
    if (finalizedRequests.empty()) return;

    cout << formatDate(finalizedDate) << " 물품 신청 완료!\n";
}
