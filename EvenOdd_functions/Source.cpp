#include<iostream>
using namespace std;
using std::cout;

void FillRand(int arr[], const unsigned int n);
void Print(int arr[], const unsigned int n);
int EvenCount(int arr[], const unsigned int n);
int OddCount(int arr[], const unsigned int n);
int* getEven(int arr[], const unsigned int n);
int* getOdd(int arr[], const unsigned int n);

void main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	cout << "Количество чётных элементов: " << EvenCount(arr, n) << endl;
	cout << "Количество нечётных элементов: " << OddCount(arr, n) << endl;

	int* even_arr = getEven(arr, n);
	int* odd_arr = getOdd(arr, n);

	Print(even_arr, EvenCount(arr, n));
	Print(odd_arr, OddCount(arr, n));

	delete[] odd_arr;
	delete[] even_arr;
	delete[] arr;
}


void FillRand(int arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		//Используя арифметику указателей и оператор разименования:
		*(arr + i) = rand() % 100;
	}
}

void Print(int arr[], const unsigned int n)
{
	for (int i = 0; i < n; i++)
	{
		//или же через оператор индексирования[]:
		cout << arr[i] << "\t";
	}
	cout << endl;
}

int EvenCount(int arr[], const unsigned int n)
{
	int even_count = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0) even_count++;
	}
	return even_count;
}

int OddCount(int arr[], const unsigned int n)
{
	return n - EvenCount(arr, n);
}

int* getEven(int arr[], const unsigned int n)
{
	int *even_arr = new int[EvenCount(arr, n)]{};
	for (int i = 0, j = 0; i < n; i++)
	{
		if (arr[i] % 2 == 0) even_arr[j++] = arr[i];
	}
	return even_arr;
}

int* getOdd(int arr[], const unsigned int n)
{
	int* odd_arr = new int[OddCount(arr, n)]{};
	for (int i = 0, j = 0; i < n; i++)
	{
		if (arr[i] % 2 != 0) odd_arr[j++] = arr[i];
	}
	return odd_arr;
}