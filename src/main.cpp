#include <iostream>
#include "items.h"
#include "requests.h"
#include "approve.h"
#include "finalize.h"
#include "display.h"
using namespace std;

int main() {
    vector<Item> itemList;
    if (!loadItemListFromCSV("data/staff_list_CSV.csv", itemList)) {
        return 1;
    }

    int choice;
    while (true) {
        displayInitialScreen();
        cout << "\n[물품 신청 프로그램]\n";
        cout << "1. 물품 리스트 보기\n";
        cout << "2. 물품 신청하기\n";
        cout << "3. 신청 리스트 보기\n";
        cout << "4. 관리자 승인\n";
        cout << "5. 주간 신청 완료 처리\n";
        cout << "0. 종료\n";
        cout << "선택: ";
        cin >> choice;

        switch (choice) {
            case 1: printItemList(itemList); break;
            case 2: applyItem(itemList); break;
            case 3: printRequestList(); break;
            case 4: processApplications(itemList); break;
            case 5: finalizeWeeklyApplications(); break;
            case 0: return 0;
            default: cout << "잘못된 입력입니다.\n";
        }
    }
}
