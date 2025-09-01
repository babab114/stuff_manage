#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <chrono>
using namespace std;

string formatDate(const chrono::system_clock::time_point& tp);

#endif
