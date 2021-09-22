//DynamicArrays
#include<iostream>
using namespace std;
using std::cout;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* Push_Back(int arr[], int& n, int value);
int* Push_Front(int arr[], int& n, int value);
int* Pop_Back(int arr[], int& n);
int* Pop_Front(int arr[], int& n);
int* Insert(int arr[], int& n, int value, int index_value);
int* Erase(int arr[], int& n, int value, int index_value);

void main()
{
	//cout << int() << endl; // выводим значение по умолчанию для типа данных int
	setlocale(LC_ALL, "Russian");
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
		cout << arr[i] << "\t";
	}
}

int* Push_Back(int arr[], int& n, int value)
{
	cout << "Добавим значение в конец массива: " << endl;
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
	return arr;
}

int* Push_Front(int arr[], int& n, int value)
{
	cout << "Добавим значение в начало массива: " << endl;
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}

int* Pop_Back(int arr[], int& n)
{
	cout << "Удалим последний элемент массива: " << endl;
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}

int* Pop_Front(int arr[], int& n)
{
	cout << "Удалим первый элемент массива: " << endl;
	int* buffer = new int[n - 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}

int* Insert(int arr[], int& n, int value, int index_value)
{
	cout << "Добавим значение по указанному индексу: " << endl;
	int* buffer = new int[n + 1]{};
	for (int i = 0; i <= index_value; i++)
	{
		i != index_value ? buffer[i] = arr[i] : buffer[i] = value;
	}
	for (int i = index_value; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n++;
	return arr;
}

int* Erase(int arr[], int& n, int value, int index_value)
{
	cout << "Удалим значение по указанному индексу: " << endl;
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < index_value; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index_value; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}