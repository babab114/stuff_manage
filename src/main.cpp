#include <iostream>
#include "requests.h"
using namespace std;

int main() {
    vector<Item> itemList;

    int choice;
    while (true) {
        cout << "\n[물품 신청 프로그램]\n";
        cout << "1. 물품 신청하기\n";
        cout << "2. 신청 리스트 보기\n";
        cout << "0. 종료\n";
        cout << "원하는 기능을 선택하세요: ";
        cin >> choice;
        
        // 입력 오류 처리 (숫자 입력 검사)
        if (cin.fail()) {
            cout << "오류: 잘못된 입력입니다. 숫자를 입력해주세요.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1; // default case 로 이동
        }

        switch (choice) {
            case 1: applyItem(itemList); break; 
            case 2: printRequestList(); break; 
            case 0: cout << "프로그램을 종료합니다.\n"; return 0;
            default: cout << "잘못된 선택입니다. 다시 입력해주세요.\n";
        }
    }
    return 0;
}
