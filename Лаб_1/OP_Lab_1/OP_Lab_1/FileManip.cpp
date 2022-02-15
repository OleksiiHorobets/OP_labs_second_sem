#include "FileManip.h"

void createInputData(string fileName, int& strCount) {
    const int BREAK_ASCII_CODE = 23;
    ofstream fout;

    fout.open(fileName);
    if (!fout.is_open()) {
        cout << "File open error!" << endl;
        return;
    }
    string line;

    cout << "Enter your text (To stop enter Ctrl + W):" << endl;

    getline(cin, line);
    while (int(line[0]) != BREAK_ASCII_CODE) {
        if (strCount)fout << '\n';
        
        fout << line;
        strCount++;
        getline(cin, line);
    }
    fout.close();
}

void displayData(string msg, string fileName)
{
    cout << msg;
    ifstream fin;
    fin.open(fileName);
    if (!fin.is_open()) {
        cout << "File open error!" << endl;
        return;
    }
    char ch;
    while (fin.get(ch)) {
        cout << ch;
    }
    fin.close();
}

string* getData(int strCount, string fileName)
{
    string* text = new string[strCount];
    string line;

    ifstream fin;
    fin.open(fileName);

    if (!fin.is_open()) {
        cout << "File open error!" << endl;
        return nullptr;
    }

    int counter = 0;
    while (!fin.eof()) {
        getline(fin, line);
        text[counter] = line;
        counter++;
    }
    fin.close();
    return text;
}

void displayText(string msg, string* text, int counter)
{
    cout << msg;
    for (int i = 0; i < counter -1; i++)
    {
        cout << text[i] << endl;
    }
    cout << text[counter-1];
}

void sortText(string* text, int counter)
{
    for (int i = 0; i < counter; i++)
    {
        for (int j = 0; j < counter -1; j++)
        {
            if (text[j].length() > text[j+1].length()) {
                string temp = text[j+1];
                text[j+1] = text[j];
                text[j] = temp;
            }
        }
    }
}

void addLength(string* text, int counter)
{
    for (int i = 0; i < counter; i++)
    {
        text[i] +="<-" + to_string(text[i].length());
    }
}

void createDataOutput(string* text, int counter, string outputFile)
{
    ofstream fout;
    fout.open(outputFile);
    if (!fout.is_open()) {
        cout << "File open error!" << endl;
        return;
    }
    for (int i = 0; i < counter-1; i++)
    {
        fout << text[i] << endl;
    }
    fout << text[counter - 1];
    fout.close();
}
