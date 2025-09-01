#include <iostream>
#include <limits>
#include "requests.h"
using namespace std;

vector<Request> requestList;

void applyItem(const vector<Item>& itemList){ 
    int itemNumber;
    int quantity;
    string requester;

    cout << "\n[물품 신청]\n";
    cout << "신청할 물품 번호를 입력하세요: ";
    cin >> itemNumber;

    cout << "신청 수량을 입력하세요: ";
    cin >> quantity;
    cout << "신청자 이름을 입력하세요: ";
    cin >> requester;

// 신청 정보 생성 및 신청 리스트에 추가
    Request newRequest;
    newRequest.itemNumber = itemNumber;
    newRequest.quantity = quantity;
    newRequest.requester = requester; 
    newRequest.approved = false;
    requestList.push_back(newRequest);

    cout << "신청이 완료되었습니다. 관리자 승인을 기다려주세요.\n";
}

void printRequestList() { // 신청 리스트 출력
    cout << "\n[신청 리스트 (승인 대기)]\n";
    cout << "----------------------\n";
    if (requestList.empty()) {
        cout << "신청 리스트가 비어 있습니다.\n";
    } else {
        for (const auto& request : requestList) {
            cout << "신청자: " << request.requester << "\n";
            cout << "물품 번호: " << request.itemNumber << "\n";
            cout << "수량: " << request.quantity << "\n";
            cout << "승인 상태: " << (request.approved ? "승인됨" : "승인 대기") << "\n";
            cout << "----------------------\n";
        }
    }
}