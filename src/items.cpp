#include <iostream>
#include <fstream>
#include <sstream>
#include "items.h"
using namespace std;

bool loadItemListFromCSV(const string& filename, vector<Item>& itemList) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "오류: CSV 파일 '" << filename << "'을 열 수 없습니다.\n";
        return false;
    }

    string line;
    getline(file, line); // 첫 줄(헤더) 건너뜀

    while (getline(file, line)) {
        stringstream ss(line);
        string segment;
        vector<string> row_data;

        while (getline(ss, segment, ',')) {
            row_data.push_back(segment);
        }

        if (row_data.size() == 3) {
            Item newItem;
            newItem.number = stoi(row_data[0]);
            newItem.name = row_data[1];
            newItem.unit = row_data[2];
            itemList.push_back(newItem);
        }
    }

    file.close();
    return true;
}

void printItemList(const vector<Item>& itemList) {
    cout << "\n[물품 리스트]\n";
    cout << "----------------------\n";
    for (const auto& item : itemList) {
        cout << "번호: " << item.number << "\n";
        cout << "이름: " << item.name << "\n";
        cout << "단위: " << item.unit << "\n";
        cout << "----------------------\n";
    }
}
