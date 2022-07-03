#include <iostream>
#include "Common.h"
#include "DinamicArray.h"

using namespace std;

/// @brief ������� ������ ������������� ������� �� �����
/// @param dinamicArray ���������� ��������� ������������ ������
void PrintArray(DinamicArray& dinamicArray)
{
    cout << "\n\n������: ";
    for (int i = 0; i < dinamicArray.Length; i++)
    {
        cout << dinamicArray.Array[i] << "   ";
    }
    cout << "\n";
}

int main()
{
    setlocale(LC_ALL, "rus");
    DinamicArray dinamicArray;
    while (true)
    {
        if (dinamicArray.CheckArrayCreate == true)
        {
            PrintArray(dinamicArray);
        }
        cout << "\n��� �� ������ �������?\n";
        if (dinamicArray.CheckArrayCreate == false)
        {
            cout << "0: ������� ������\n";
        }
        cout << "1: �������� �������\n";
        cout << "2: ������� �������\n";
        cout << "3: ������������� ������\n";
        cout << "4: ����� ������� � �������\n";
        cout << "5: ����� �� ���������\n";
        cout << "\n������� ��� ������� ��������: ";
        int menuNumber = ReadingCorrectValue();
        switch (menuNumber)
        {
            case ArrayCreationMenuItem:
            {
                if (dinamicArray.CheckArrayCreate == false)
                {
                    MakeArray(dinamicArray);
                    int size = ReadingCorrectSize();
                    for (int i = 0; i < size; i++)
                    {
                        cout << "������� ������� ������� " << i + 1 << ": ";
                        int addElement = ReadingCorrectValue();
                        AddIndex(dinamicArray, addElement, 0, AddEndItem);
                    }
                    dinamicArray.CheckArrayCreate = true;
                    system("pause");
                }
                break;
            }
            case AddMenuItem:
            {
                if (dinamicArray.CheckArrayCreate == false)
                {
                    cout << "������ �� ������\n";
                    cout << "������� � ������� ����\n\n";
                    system("pause");
                    break;
                }
                cout << "\n���� ������ �������� �������?\n";
                cout << "1: �������� ������� � ������\n";
                cout << "2: �������� ������� � �����\n";
                cout << "3: �������� ������� ����� ������������� ��������\n";
                cout << "��� ������ � ������� ���� ";
                cout << "������� ����� �����, ����� ������������\n";
                cout << "\n������� ��� ������� ��������: ";
                int localNumber = ReadingCorrectValue();
                cout << "\n";
                switch (localNumber)
                {
                    case AddBeginItem:
                    {
                        cout << "*�� ������ �������� ������� � ������*\n";
                        cout << "\n������� ����������� � ������ �������: ";
                        int addElement = ReadingCorrectValue();
                        AddIndex(dinamicArray, addElement, 0, AddBeginItem);
                        break;
                    }
                    case AddEndItem:
                    {
                        cout << "*�� ������ �������� ������� � �����*\n";
                        cout << "\n������� ����������� � ������ �������: ";
                        int addElement = ReadingCorrectValue();
                        AddIndex(dinamicArray, addElement, 0, AddEndItem);
                        break;
                    }
                    case AddIndexItem:
                    {
                        cout << "*�� ������ �������� ������� ����� ";
                        cout << "������������� ��������*\n";
                        int index;
                        while (true)
                        {
                            cout << "������� ����� ��������,";
                            cout << "����� �������� ������ �������: ";
                            index = ReadingCorrectValue();
                            if (index > dinamicArray.Length)
                            {
                                cout << "\n�� ��������\n";
                                cout << "������� ������ ���������\n";
                                cout << "���������� ��������: ";
                                cout << dinamicArray.Length;
                                cout << " \n";
                            }
                            else
                            {
                                break;
                            }
                        }
                        cout << "\n������� ����������� � ������ �������: ";
                        int addElement = ReadingCorrectValue();
                        AddIndex(dinamicArray, addElement, index-1, AddIndexItem);
                        break;
                    }
                    default:
                    {
                        cout << "\n*�� ������ ��������� ";
                        cout << "� ������� ����*\n";
                        break;
                    }
                }
                system("pause");
                break;
            }
            case DeleteMenuItem:
            {
                if (dinamicArray.CheckArrayCreate == false)
                {
                    cout << "������ �� ������\n";
                    cout << "������� � ������� ����\n\n";
                    system("pause");
                    break;
                }
                if (dinamicArray.Length == 0)
                {
                    cout << "������ ����\n";
                    cout << "������� � ������� ����\n\n";
                    system("pause");
                    break;
                }                
                cout << "*�� ������ ������� ������������ �������*\n";
                cout << "������� ����� ��������, ������� ������ �������: ";
                int index = ReadingCorrectValue();
                if (index > dinamicArray.Length)
                {
                    cout << "\n�� ��������\n������ ������ ������ �������";
                    cout << "\n������� � ������� ����\n";
                    break;
                }
                DeleteIndex(dinamicArray, index-1);
                system("pause");
                break;
            }
            case SortMenuItem:
            {
                if (dinamicArray.CheckArrayCreate == false)
                {
                    cout << "������ �� ������\n";
                    cout << "������� � ������� ����\n\n";
                    system("pause");
                    break;
                }
                if (dinamicArray.Length == 0)
                {
                    cout << "������ ����\n";
                    cout << "������� � ������� ����\n\n";
                    system("pause");
                    break;
                }
                cout << "\n*�� ������ ������������� ������*\n";
                cout << "\n������ ������������ ������� ��������";
                cout << " � ������� �����������\n";
                Sort(dinamicArray);
                system("pause");
                break;
            }
            case SearchMenuItem:
            {
                if (dinamicArray.CheckArrayCreate == false)
                {
                    cout << "������ �� ������\n";
                    cout << "������� � ������� ����\n\n";
                    system("pause");
                    break;
                }
                if (dinamicArray.Length == 0)
                {
                    cout << "������ ����\n";
                    cout << "������� � ������� ����\n\n";
                    system("pause");
                    break;
                }
                cout << "\n�������� ����� ������\n";
                cout << "1:�������� �����\n";
                cout << "2:�������� �����\n";
                cout << "��� ������ � ������� ���� ������� ����� �����,";
                cout << " ����� ������������\n";
                cout << "������� ��� ������� ��������: ";
                int localNumber = ReadingCorrectValue();
                cout << "\n";
                switch (localNumber)
                {
                    case LineSearchItem:
                    {
                        cout << "*�� ������� �������� �����*\n";
                        cout << "������� �������, ������� �� ������ �����: ";
                        int searchKey = ReadingCorrectValue();
                        if (LineSearch(dinamicArray, searchKey) == -1)
                        {
                            cout << "\n������� �� ������\n";
                        }
                        else
                        {
                            cout << "\n����� �������� ";
                            cout << searchKey;
                            cout << " : ";
                            cout << LineSearch(dinamicArray, searchKey) + 1;
                            cout << "\n";
                        }
                        break;
                    }
                    case BinarySearchItem:
                    {
                        cout << "*�� ������� �������� �����*\n";
                        cout << "\n*��� ������ ����� ������ ������ �����";
                        cout << " ������������ ������� ��������*\n";
                        cout << "������� �������, ������� �� ������ �����: ";
                        int searchKey = ReadingCorrectValue();
                        Sort(dinamicArray);
                        if (BinarySearch(dinamicArray, searchKey) == -1)
                        {
                            cout << "\n������� �� ������\n";
                        }
                        else
                        {
                            cout << "\n����� �������� ";
                            cout << searchKey;
                            cout << " : ";
                            cout << BinarySearch(dinamicArray, searchKey) + 1;
                            cout << "\n";
                        }
                        break;
                    }
                    default:
                    {
                        cout << "\n*�� ������ ��������� � ������� ����*\n";
                        break;
                    }
                }
                system("pause");
                break;
            }
            case ExitMenuItem:
            {
                cout << "\n*�� ������ ����� �� ���������*\n";
                if (dinamicArray.CheckArrayCreate == true)
                {
                    delete[] dinamicArray.Array;
                }
                return 0;
            }
            default:
            {
                cout << "�� ��������\n����������, ������� ���������\n\n";
                system("pause");
                break;
            }
        }
    }
}