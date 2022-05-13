#include "LineFunctions.h"

Line* createLineArr(int& arrSize)
{
	cout << "Enter lines ammount: ";
	cin >> arrSize;
	Line* lines = new Line[arrSize];

	for (int i = 0; i < arrSize; i++)
	{
		cin >> lines[i];
	}

	return lines;
}

void displayLineArr(Line* lines, int arrSize, string msg)
{
	for (int i = 0; i < arrSize; i++)
	{
		cout << lines[i];
	}
}

vector<int> getLineIndxesWithPoint(Line* lines, int lines_size, Point& point)
{
	vector<int> indexes;
	for (int i = 0; i < lines_size; i++)
	{
		if (lines[i].lineContainsPoint(point)) {
			indexes.push_back(i);
		}
	}
	return indexes;
}

void displayVector(vector<int> vec, string msg) {
	cout << msg;
	for (int  i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}





