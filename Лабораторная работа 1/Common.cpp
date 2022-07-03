#include "Common.h"
#include <iostream>

using namespace std;

int ReadingCorrectValue()
{
    int value;
    while (true)
    {
        if (cin >> value)
        {
            break;
        }
        cout << "� ���������, �� ��������\n";
        cout << "(�������� �������� ������ ���� ����� ������)\n";
        cout << "������� �����: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return value;
}

int ReadingCorrectSize()
{
    int size;
    while (true)
    {
        cout << "������� ���������� ��������� ���������� ���������: ";
        cin >> size;
        if (size <= 0)
        {
            cout << "� ���������, �� ��������\n";
            cout << "(��������� ���������� ������ ���� �����";
            cout << " ������ ������ 0)\n";
            cout << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            break;
        }
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return size;
}
