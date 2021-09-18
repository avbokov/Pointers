//DynamicArrays
#include<iostream>
using namespace std;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	cout << int() << endl; // выводим значение по умолчанию для типа данных int
	setlocale(LC_ALL, "Russian");
	int n; // размер массива
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n]{}; //Heap


	//Обращаться к элементам массива можно
	FillRand(arr, n);
	Print(arr, n);

	cout << endl;
	//TODO:
	//Добавить значение в конец массива
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
	Print(arr, n);

	delete[] arr;

}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Используя арифметику указателей и оператор разименования:
		*(arr + i) = rand() % 100;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//или же через оператор индексирования[]:
		cout << arr[i]<< "\t";
	}
}