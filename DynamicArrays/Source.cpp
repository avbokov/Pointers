//DynamicArrays
#include<iostream>
using namespace std;
using std::cout;
using std::cin;

#include"Array.h"
#include"Memory.h"

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	//cout << int() << endl; // выводим значение по умолчанию для типа данных 'int'
	setlocale(LC_ALL, "Russian");
#ifdef DYNAMIC_MEMORY_1
	int n; // размер массива
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {}; //Heap

	//Обращаться к элементам массива можно
	FillRand(arr, n);
	Print(arr, n);
	cout << endl;

	int value;
	int index_value;
	cout << "Введите добавляемое значение в массив: "; cin >> value;
	cout << "Введите индекс добавляемого/удаляемого значения (от 0 до " << n - 1 << "): "; cin >> index_value;

	//TODO:
	//Добавить значение в конец массива
#ifdef ONE
	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	//1) Создаём буферный массив нужного размера:
	int* buffer = new int[n + 1]{};
	//2) Переносим все значения из исходного массива в буферный.
	//Копируем исходный массив в буферный СООТВЕТСТВЕННО
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) Удаляем исходный массив:
	delete[] arr;
	//4) Подменяем старый массив на новый
	arr = buffer;
	//5) только после всего этого, можно добавить значение в конец массива,
	// поскольку в конце массива появился элемент, в который можно сохранить значение:
	arr[n] = value;
	//6) после добавления элемента в массив, количество его элементов увеличивается на 1:
	n++;
#endif ONE

	arr = Erase(arr, n, value, index_value);
	Print(arr, n);

	delete[] arr;

#endif DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows; // Количество строк
	int cols; // Количество элементов строки
	cout << "Введите количесво строк (rows): "; cin >> rows;
	cout << "Введите количесво элементов строки (cols): "; cin >> cols;
	////////// Объявление двумерного динамического массива //////////

	int** arr = Allocate(rows, cols);
	//1) Создаём массив указателей 
	//int** arr = new int* [rows] {};
	////2) Создаём строки
	//for (int i = 0; i < rows; i++)
	//{
	//	arr[i] = new int[cols] {};
	//}
	//cout << "Массив создан, сейчас будем добавлять строку";
	////////// Использование двумерного динамического массива //////////
	cout << endl;
	//system("PAUSE");
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << endl;

	int index;
	int* stroka = new int[cols] {147}; //Heap
	cout << "Добавляемая строка (столбец): " << endl << endl;
	Print(stroka, cols);
	cout << endl << endl;
	cout << "Введите индекс добавляемой (удаляемой) строки (столбца), от 0 до " << rows << " (от 0 до " << cols << "): "; cin >> index;
	cout << endl << endl;

	arr = Push_Row_Back(arr, rows, cols, stroka);
	//arr = Push_Col_Back(arr, rows, cols, stroka);

	//arr = Push_Row_Front(arr, rows, cols, stroka);
	//arr = Push_Col_Front(arr, rows, cols, stroka);

	//arr = Pop_Row_Back(arr, rows, cols);
	//arr = Pop_Col_Back(arr, rows, cols);

	//arr = Pop_Row_Front(arr, rows, cols);
	//arr = Pop_Col_Front(arr, rows, cols);

	//arr = Insert_Row(arr, rows, cols, stroka, index);
	//arr = Insert_Col(arr, rows, cols, stroka, index);

	//arr = Erase_Row(arr, rows, cols, index);
	//arr = Erase_Col(arr, rows, cols, index);

	//cout << "Строка добавлена" << endl;
	//FillRand(arr[rows - 1], cols, 200, 1000);

	//Push_Col_Back(arr, rows, cols);
	//Pop_col_Back(arr, rows, cols);

	Print(arr, rows, cols);
	cout << endl;

	////////// Удаление двумерного динамического массива //////////
	//1) Удаляем строки
	//for (int i = 0; i < rows; i++)
	//{
	//	delete[] arr[i];
	//}
	////2) Удаляем массив указателей
	//delete[] arr;

	Clear(arr, rows);

#endif DYNAMIC_MEMORY_2
}




