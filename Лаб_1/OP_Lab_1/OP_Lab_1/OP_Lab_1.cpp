#include <iostream>
#include <fstream>
#include "FileManip.h"

using namespace std;

int main()
{
    string inputFile = "inputData.txt";
    string outputFile = "outputData.txt";

    int strCount = 0;

    createInputData(inputFile, strCount);

    displayData("\n--------Initial data--------\n\n", inputFile);

    string* text = getData(strCount, inputFile);
    
    displayText("\n------Array of strings-------\n\n", text, strCount);

    sortText(text, strCount);

    displayText("\n------Sorted text-------\n", text, strCount);

    addLength(text, strCount);

    displayText("\n------Added length of each line in text-------\n", text, strCount);

    createDataOutput(text, strCount, outputFile);

    displayData("\n--------Output data--------\n\n", outputFile);

    return 0;
}