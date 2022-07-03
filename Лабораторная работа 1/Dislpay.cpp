#include <iostream>
#include "Common.h"
#include "DinamicArray.h"

using namespace std;

/// @brief Функция вывода Динамического массива на экран
/// @param dinamicArray Переменная структуры Динамический Массив
void PrintArray(DinamicArray& dinamicArray)
{
    cout << "\n\nМассив: ";
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
        cout << "\nЧто вы хотите сделать?\n";
        if (dinamicArray.CheckArrayCreate == false)
        {
            cout << "0: Создать массив\n";
        }
        cout << "1: Добавить элемент\n";
        cout << "2: Удалить элемент\n";
        cout << "3: Отсортировать массив\n";
        cout << "4: Найти элемент в массиве\n";
        cout << "5: Выйти из программы\n";
        cout << "\nВведите ваш вариант действий: ";
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
                        cout << "Введите элемент массива " << i + 1 << ": ";
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
                    cout << "Массив не создан\n";
                    cout << "Возврат в главное меню\n\n";
                    system("pause");
                    break;
                }
                cout << "\nКуда хотите добавить элемент?\n";
                cout << "1: Добавить элемент в начало\n";
                cout << "2: Добавить элемент в конец\n";
                cout << "3: Добавить элемент после определенного элемента\n";
                cout << "Для выхода в главное меню ";
                cout << "введите любую цифру, кроме предложенных\n";
                cout << "\nВведите ваш вариант действий: ";
                int localNumber = ReadingCorrectValue();
                cout << "\n";
                switch (localNumber)
                {
                    case AddBeginItem:
                    {
                        cout << "*Вы решили добавить элемент в начало*\n";
                        cout << "\nВведите добавляемый в массив элемент: ";
                        int addElement = ReadingCorrectValue();
                        AddIndex(dinamicArray, addElement, 0, AddBeginItem);
                        break;
                    }
                    case AddEndItem:
                    {
                        cout << "*Вы решили добавить элемент в конец*\n";
                        cout << "\nВведите добавляемый в массив элемент: ";
                        int addElement = ReadingCorrectValue();
                        AddIndex(dinamicArray, addElement, 0, AddEndItem);
                        break;
                    }
                    case AddIndexItem:
                    {
                        cout << "*Вы решили добавить элемент после ";
                        cout << "определенного элемента*\n";
                        int index;
                        while (true)
                        {
                            cout << "Введите номер элемента,";
                            cout << "после которого хотите вставку: ";
                            index = ReadingCorrectValue();
                            if (index > dinamicArray.Length)
                            {
                                cout << "\nВы ошиблись\n";
                                cout << "Введите индекс правильно\n";
                                cout << "Количество индексов: ";
                                cout << dinamicArray.Length;
                                cout << " \n";
                            }
                            else
                            {
                                break;
                            }
                        }
                        cout << "\nВведите добавляемый в массив элемент: ";
                        int addElement = ReadingCorrectValue();
                        AddIndex(dinamicArray, addElement, index-1, AddIndexItem);
                        break;
                    }
                    default:
                    {
                        cout << "\n*Вы решили вернуться ";
                        cout << "в главное меню*\n";
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
                    cout << "Массив не создан\n";
                    cout << "Возврат в главное меню\n\n";
                    system("pause");
                    break;
                }
                if (dinamicArray.Length == 0)
                {
                    cout << "Массив пуст\n";
                    cout << "Возврат в главное меню\n\n";
                    system("pause");
                    break;
                }                
                cout << "*Вы решили удалить определенный элемент*\n";
                cout << "Введите номер элемента, который хотите удалить: ";
                int index = ReadingCorrectValue();
                if (index > dinamicArray.Length)
                {
                    cout << "\nВы ошиблись\nИндекс больше длинны Массива";
                    cout << "\nВозврат в главное меню\n";
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
                    cout << "Массив не создан\n";
                    cout << "Возврат в главное меню\n\n";
                    system("pause");
                    break;
                }
                if (dinamicArray.Length == 0)
                {
                    cout << "Массив пуст\n";
                    cout << "Возврат в главное меню\n\n";
                    system("pause");
                    break;
                }
                cout << "\n*Вы решили отсортировать массив*\n";
                cout << "\nМассив отсортирован методом пузырька";
                cout << " в порядке возрастания\n";
                Sort(dinamicArray);
                system("pause");
                break;
            }
            case SearchMenuItem:
            {
                if (dinamicArray.CheckArrayCreate == false)
                {
                    cout << "Массив не создан\n";
                    cout << "Возврат в главное меню\n\n";
                    system("pause");
                    break;
                }
                if (dinamicArray.Length == 0)
                {
                    cout << "Массив пуст\n";
                    cout << "Возврат в главное меню\n\n";
                    system("pause");
                    break;
                }
                cout << "\nВыберите метод поиска\n";
                cout << "1:Линейный поиск\n";
                cout << "2:Бинарный поиск\n";
                cout << "Для выхода в главное меню введите любую цифру,";
                cout << " кроме предложенных\n";
                cout << "Введите ваш вариант действий: ";
                int localNumber = ReadingCorrectValue();
                cout << "\n";
                switch (localNumber)
                {
                    case LineSearchItem:
                    {
                        cout << "*Вы выбрали линейный поиск*\n";
                        cout << "Введите элемент, который вы хотите найти: ";
                        int searchKey = ReadingCorrectValue();
                        if (LineSearch(dinamicArray, searchKey) == -1)
                        {
                            cout << "\nЭлемент не найден\n";
                        }
                        else
                        {
                            cout << "\nНомер элемента ";
                            cout << searchKey;
                            cout << " : ";
                            cout << LineSearch(dinamicArray, searchKey) + 1;
                            cout << "\n";
                        }
                        break;
                    }
                    case BinarySearchItem:
                    {
                        cout << "*Вы выбрали бинарный поиск*\n";
                        cout << "\n*Для работы этого метода массив будет";
                        cout << " отсортирован методом пузырька*\n";
                        cout << "Введите элемент, который вы хотите найти: ";
                        int searchKey = ReadingCorrectValue();
                        Sort(dinamicArray);
                        if (BinarySearch(dinamicArray, searchKey) == -1)
                        {
                            cout << "\nЭлемент не найден\n";
                        }
                        else
                        {
                            cout << "\nНомер элемента ";
                            cout << searchKey;
                            cout << " : ";
                            cout << BinarySearch(dinamicArray, searchKey) + 1;
                            cout << "\n";
                        }
                        break;
                    }
                    default:
                    {
                        cout << "\n*Вы решили вернуться в главное меню*\n";
                        break;
                    }
                }
                system("pause");
                break;
            }
            case ExitMenuItem:
            {
                cout << "\n*Вы решили выйти из программы*\n";
                if (dinamicArray.CheckArrayCreate == true)
                {
                    delete[] dinamicArray.Array;
                }
                return 0;
            }
            default:
            {
                cout << "Вы ошиблись\nПожалуйста, введите правильно\n\n";
                system("pause");
                break;
            }
        }
    }
}