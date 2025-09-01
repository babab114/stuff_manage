#ifndef REQUESTS_H
#define REQUESTS_H

#include "items.h"
#include <vector>
#include <string>
using namespace std;

struct Request {
    int itemNumber;
    int quantity;
    string requester;
    bool approved;
};

extern vector<Request> requestList;

void applyItem(const vector<Item>& itemList);
void printRequestList();

#endif
