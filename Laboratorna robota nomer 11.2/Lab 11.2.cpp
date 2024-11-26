// Lab 11.2

#include <iostream>
#include <fstream>
#include <string>
#include <cctype> 
#include <Windows.h>

using namespace std;

bool startsWithB(const string& word) 
{
    return !word.empty() && (tolower(word[0]) == 'b');
}

int main() 
{
    SetConsoleCP(1251);    
    SetConsoleOutputCP(1251);
    ofstream outFile("text.txt");  
    if (!outFile) 
    {
        cerr << "�� ������� �������� ����!" << endl;
        return 1;
    }

    cout << "������ ����� ��� ������ � ���� (�������� Enter):" << endl;
    string inputText;
    getline(cin, inputText);
    outFile << inputText;
    outFile.close();

    ifstream inFile("text.txt");
    if (!inFile) 
    {
        cerr << "�� ������� ������� ����!" << endl;
        return 1;
    }

    int wordCount = 0;
    string word;
    while (inFile >> word) 
    { 
        if (startsWithB(word)) 
        {
            wordCount++;
        }
    }
    inFile.close();

    cout << "ʳ������ ���, �� ����������� �� 'b' ��� 'B': " << wordCount << endl;

    return 0;
}
