#pragma once
#include "Line.h"
#include "Point.h"
#include <vector>

Line* createLineArr(int& arrSize);

void displayLineArr(Line* lines, int arrSize, string msg);

vector<int> getLineIndxesWithPoint(Line* lines, int lines_size, Point& point);

void displayVector(vector<int> vec, string msg);