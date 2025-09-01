#include <iostream>
#include "requests.h"
#include "aprove.h"
using namespace std;

int main() {
    vector<Item> itemList;
    
    if (!loadItemListFromCSV("staff_list_CSV.csv", itemList)) {
        cerr << "오류: CSV 파일 로드 실패. 프로그램을 종료합니다.\n";
        return 1;
    }

    int choice;
    while (true) {
        cout << "\n[물품 신청 프로그램]\n";
        cout << "1. 물품 리스트 보기\n";
        cout << "2. 물품 신청하기\n";
        cout << "3. 신청 리스트 보기\n"; // 메뉴 이름 변경
        cout << "4. 관리자 승인\n";
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
            case 1: printItemList(itemList); break;
            case 2: applyItem(itemList); break;
            case 3: printRequestList(); break;
            case 4: processApplications(itemList); break;
            case 0: cout << "프로그램을 종료합니다.\n"; return 0;
            default: cout << "잘못된 선택입니다. 다시 입력해주세요.\n";
        }
    }
    return 0;
}



