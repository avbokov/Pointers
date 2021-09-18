#include<iostream>
using namespace std;
using std::cout;

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "Russian");
	int n; // размер исходного массива
	int SIZE_ODD = 0; // нечётные значения
	int SIZE_EVEN = 0; // чётные значения

	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {};
		
	FillRand(arr, n);
	Print(arr, n);

	cout << endl;

	for (int i = 0; i < n; i++)
	{
		arr[i] % 2 == 0 ? SIZE_EVEN++ : SIZE_ODD++; // пробуем в тернарник )), 0 отнесём к четным числам, поэтому условие именно такое и счётчик чётных ставим первым
	}

	cout << "Чётных значение в массиве: " << SIZE_EVEN << " шт." << endl;
	cout << "Нечётных значение в массиве: " << SIZE_ODD << " шт." << endl;

	int* odd = new int[SIZE_ODD] {};
	int* even = new int[SIZE_EVEN] {};
	
	SIZE_ODD = 0;
	SIZE_EVEN = 0;

	for (int i = 0; i < n; i++)
	{
		//arr[i] % 2 == 0 ? even[SIZE_EVEN] = arr[i], SIZE_EVEN++ : odd[SIZE_ODD] = arr[i], SIZE_ODD++; - так и не понял, почему не работает корректно
		if (arr[i] % 2 == 0)
		{
			even[SIZE_EVEN] = arr[i];
			SIZE_EVEN++;
		}
		else
		{
			odd[SIZE_ODD] = arr[i];
			SIZE_ODD++;
		}
	}

	cout << "Массив чётных значений: "; Print(even, SIZE_EVEN);
	cout << endl;
	cout << "Массив нечётных значений: "; Print(odd, SIZE_ODD);

	delete[] odd;
	delete[] even;
	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
}