#include <iostream>
#include "Line.h"
#include "Point.h"
#include "LineFunctions.h"
#include <vector>

using namespace std;

int main()
{
	int linesSize = 0;
	Line* lines = createLineArr(linesSize);
	
	displayLineArr(lines, linesSize, "\n---------Lines arr---------\n");
	
	Point point;

	cout << "Enter point coordinates"<<endl;
	cin >> point;


	vector<int> index_vec = getLineIndxesWithPoint(lines, linesSize, point);

	displayVector(index_vec, "\nIndexes of lines that contain a point\n");
}