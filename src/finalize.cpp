#include <iostream>
#include <vector>
#include <chrono>
#include "requests.h"
#include "utils.h"
using namespace std;

vector<Request> finalizedRequests;
chrono::system_clock::time_point finalizedDate;

void finalizeWeeklyApplications() {
    int password;
    cout << "관리자 비밀번호 입력: ";
    cin >> password;

    if (password != 4976) {
        cout << "비밀번호 오류. 완료 취소.\n";
        return;
    }

    finalizedRequests = requestList;
    finalizedDate = chrono::system_clock::now();
    requestList.clear();

    cout << "주간 신청이 완료되었습니다.\n";
}
