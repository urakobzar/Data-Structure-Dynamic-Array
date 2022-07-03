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


/// @brief Функция создания Динамического массива
/// @param dinamicArray Переменная структуры Динамический массив
void MakeArray(DinamicArray& dinamicArray);

/// @brief Функция добавления элемента в массив
/// @param dinamicArray Переменная структуры Динамический массив
/// @param digit Добавляемый элемент
/// @param index Индекс элемента, после которого идет вставка
/// @param addKey Говорит о том, куда будет вставлен элемент
void AddIndex(DinamicArray& dinamicArray, int digit, int index, AddMenuItems addKey);

/// @brief Функция удаления элемента по индексу
/// @param dinamicArray Переменная структуры Динамический массив
/// @param index Индекс удаляемого элемента
void DeleteIndex(DinamicArray& dinamicArray, int index);

/// @brief Сортировка пузырьком
/// @param dinamicArray Переменная структуры Динамический массив
void Sort(DinamicArray& dinamicArray);

/// @brief Функция линейного поиск
/// @param dinamicArray Переменная структуры Динамический массив
/// @param key Искомый элемент
/// @return Возвращает или искомый элемент, или
/// параметр, что элемент отсутствует
int LineSearch(DinamicArray& dinamicArray, int key);

/// @brief Функция Бинарного поиск
/// @param dinamicArray Переменная структуры Динамический массив
/// @param key Искомый элемент
/// @return Возвращает или искомый элемент, или
/// параметр, что элемент отсутствует
int BinarySearch(DinamicArray& dinamicArray, int key);

/// @brief Функция изменения размера Динамического массива
/// @param dynamicArray Переменная структуры Динамический массив
void Resize(DinamicArray & dinamicArray); 
