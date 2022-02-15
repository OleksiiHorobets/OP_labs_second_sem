#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createInputData(string fileName, int& strCount);

void displayData(string msg, string fileName);

string* getData(int strCount, string fileName);

void displayText(string msg, string* text, int counter);

void sortText(string* text, int counter);

void addLength(string* text, int counter);

void createDataOutput(string* text, int counter, string outputFile);