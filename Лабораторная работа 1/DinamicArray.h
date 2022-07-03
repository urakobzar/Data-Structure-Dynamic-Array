#pragma once

struct DinamicArray
{
    int* Array;
    int Length;
    int Capacity;
    bool CheckArrayCreate = false;
    const int GrowthFactor = 2;
    const int BasicCapacity = 4;
};


enum MenuItems
{
    ArrayCreationMenuItem = 0,
    AddMenuItem = 1,
    DeleteMenuItem = 2,
    SortMenuItem = 3,
    SearchMenuItem = 4,
    ExitMenuItem = 5
};

enum SearchMenuItems
{
    LineSearchItem = 1,
    BinarySearchItem = 2
};

enum AddMenuItems
{
    AddBeginItem = 1,
    AddEndItem = 2,
    AddIndexItem = 3
};


/// @brief ������� �������� ������������� �������
/// @param dinamicArray ���������� ��������� ������������ ������
void MakeArray(DinamicArray& dinamicArray);

/// @brief ������� ���������� �������� � ������
/// @param dinamicArray ���������� ��������� ������������ ������
/// @param digit ����������� �������
/// @param index ������ ��������, ����� �������� ���� �������
/// @param addKey ������� � ���, ���� ����� �������� �������
void AddIndex(DinamicArray& dinamicArray, int digit, int index, AddMenuItems addKey);

/// @brief ������� �������� �������� �� �������
/// @param dinamicArray ���������� ��������� ������������ ������
/// @param index ������ ���������� ��������
void DeleteIndex(DinamicArray& dinamicArray, int index);

/// @brief ���������� ���������
/// @param dinamicArray ���������� ��������� ������������ ������
void Sort(DinamicArray& dinamicArray);

/// @brief ������� ��������� �����
/// @param dinamicArray ���������� ��������� ������������ ������
/// @param key ������� �������
/// @return ���������� ��� ������� �������, ���
/// ��������, ��� ������� �����������
int LineSearch(DinamicArray& dinamicArray, int key);

/// @brief ������� ��������� �����
/// @param dinamicArray ���������� ��������� ������������ ������
/// @param key ������� �������
/// @return ���������� ��� ������� �������, ���
/// ��������, ��� ������� �����������
int BinarySearch(DinamicArray& dinamicArray, int key);

/// @brief ������� ��������� ������� ������������� �������
/// @param dynamicArray ���������� ��������� ������������ ������
void Resize(DinamicArray & dinamicArray); 
