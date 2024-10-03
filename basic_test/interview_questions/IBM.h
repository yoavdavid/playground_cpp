#pragma once

#include <string>

#define ADD(x) x + x
#define SUB(x) x - x
// Compute  int y = ADD(3) / SUB(3); ADD(y);

string canReach(int x1, int y1, int x2, int y2) {
    string res = "No";
    double a = (double)(x2 - x1) / (double)y1;
    double b = (double)(y2 - y1) / (double)x1;

    if ((int)a == a && (int)b == b && a >= 0 && b >= 0) {
        res = "Yes";
    }

    return res;
}