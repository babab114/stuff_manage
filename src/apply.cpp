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

    // 입력 오류 처리 (숫자 입력 검사)
    if (cin.fail()) {
        cerr << "오류: 잘못된 입력입니다. 숫자를 입력해주세요.\n";
        cin.clear(); // 오류 플래그 초기화
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 입력 버퍼 비우기
        return;
    }

    cout << "신청 수량을 입력하세요: ";
    cin >> quantity;

    // 입력 오류 처리 (숫자 입력 검사)
    if (cin.fail()) {
        cerr << "오류: 잘못된 입력입니다. 숫자를 입력해주세요.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    cout << "신청자 이름을 입력하세요: ";
    cin >> requester; 

    // 유효성 검사 및 신청 정보 생성
    bool itemExists = false;
    for (const auto& item : itemList) {
        if (item.number == itemNumber) {
            itemExists = true;
            break;
        }
    }
    if (!itemExists) {
        cout << "오류: 존재하지 않는 물품 번호입니다.\n";
        return;
    }
    if (quantity <= 0) {
        cout << "오류: 수량은 1개 이상이어야 합니다.\n";
        return;
    }

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
