#ifndef ITEMS_H
#define ITEMS_H

#include <vector>
#include <string>
using namespace std;

struct Item {
    int number;
    string name;
    string unit;
};

bool loadItemListFromCSV(const string& filename, vector<Item>& itemList);
void printItemList(const vector<Item>& itemList);

#endif
