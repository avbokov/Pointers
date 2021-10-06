//DynamicArrays
#include<iostream>
using namespace std;
using std::cout;
using std::cin;

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);

void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

template<typename T>T* Push_Back(T arr[], int& n, T value);
int** Push_Row_Back(int** arr, int& rows, const int cols, int stroka[]);
int** Push_Col_Back(int** arr, const int rows, int& cols, int stroka[]);
void Push_Col_Back(int** arr, const int rows, int& cols); // в классе


int* Push_Front(int arr[], int& n, int value);
int** Push_Row_Front(int** arr, int& rows, const int cols, int stroka[]);
int** Push_Col_Front(int** arr, const int rows, int& cols, int stroka[]);

int* Pop_Back(int arr[], int& n);
int** Pop_Row_Back(int** arr, int& rows, const int cols);
int** Pop_Col_Back(int** arr, const int rows, int& cols);
void Pop_col_Back(int** arr, const int rows, int& cols); // в классе (разные имена)

int* Pop_Front(int arr[], int& n);
int** Pop_Row_Front(int** arr, int& rows, const int cols);
int** Pop_Col_Front(int** arr, const int rows, int& cols);


template<typename T>T* Insert(T arr[], int& n, T value, int index_value);
int** Insert_Row(int** arr, int& rows, const int cols, int stroka[], int index);
int** Insert_Col(int** arr, const int rows, int& cols, int stroka[], int index);


int* Erase(int arr[], int& n, int value, int index_value);
int** Erase_Row(int** arr, int& rows, const int cols, int index);
int** Erase_Col(int** arr, const int rows, int& cols, int index);


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

	char** arr = Allocate<char>(rows, cols);
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

	//arr = Push_Row_Back(arr, rows, cols, stroka);
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

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		//Используя арифметику указателей и оператор разименования:
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
	}
}

void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
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

void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

int** Allocate(int const rows, int const cols)
{
	int** arr = new int * [rows] {};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols]{};
	}
	return arr;
}

void Clear(int** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

template<typename T>T* Push_Back(T arr[], int& n, T value)
{
	cout << "Добавим значение в конец массива: " << endl;
	T* buffer = new T[n + 1]{};
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

int** Push_Row_Back(int** arr, int& rows, const int cols, int stroka[])
{
	cout << "Добавим строку в конец массива: " << endl << endl;
	int** buffer = new int* [rows + 1]{}; // создаём указатель на массив указателей, который длиннее исходного на один и инициализируем его нулями

	buffer[rows] = stroka; //в последнюю ячейку массива указателей записываем указатель на добавляемую строку

	for (int i = 0; i < rows; i++) // копируем значения из исходного массива в буферный соответственно
	{
		buffer[i] = arr[i];
	}

	delete[] arr; // затем значение массива указателей (указатели на область памяти)

	arr = buffer; // за

	rows++;
	return arr;
}

int** Push_Col_Back(int** arr, const int rows, int& cols, int stroka[])
{
	cout << "Добавим столбец в конец массива: " << endl << endl;
	int** buffer = new int* [rows] {}; // создаём указатель на массив указателей, который длиннее исходного на один и инициализируем его нулями
	for (int i = 0; i < rows; i++) // создаём строки
	{
		buffer[i] = new int[cols + 1]{};// для каждого указателя резервируем область памяти длиной cols, в которую будеь записывать int'ы и тоже инициализируем его нулями
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		delete[] arr[i];
	}

	for (int i = 0; i < rows; i++)
	{
		buffer[i][cols] = stroka[i];
	}

	delete[] arr; // затем значение массива указателей (указатели на область памяти)

	arr = buffer; // за

	cols++;
	return arr;
}

void Push_Col_Back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
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

int** Push_Row_Front(int** arr, int& rows, const int cols, int stroka[])
{
	cout << "Добавим строку в начало массива: " << endl << endl;
	int** buffer = new int* [rows + 1]{}; // создаём указатель на массив указателей, который длиннее исходного на один и инициализируем его нулями

	buffer[0] = stroka; //в первую ячейку массива указателей записываем указатель на добавляемую строку

	for (int i = 0; i < rows; i++) // копируем значения из исходного массива в буферный соответственно
	{
		buffer[i + 1] = arr[i];
	}

	delete[] arr; // затем значение массива указателей (указатели на область памяти)

	arr = buffer; // за

	rows++;
	return arr;
}

int** Push_Col_Front(int** arr, const int rows, int& cols, int stroka[])
{
	cout << "Добавим столбец в начало массива: " << endl << endl;
	int** buffer = new int* [rows] {};
	for (int i = 0; i < rows; i++) // создаём строки
	{
		buffer[i] = new int[cols + 1]{};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j + 1] = arr[i][j];
		}
		delete[] arr[i];
	}

	for (int i = 0; i < rows; i++)
	{
		buffer[i][0] = stroka[i];
	}

	delete[] arr; // затем значение массива указателей (указатели на область памяти)

	arr = buffer; // за

	cols++;
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

int** Pop_Row_Back(int** arr, int& rows, const int cols)
{
	cout << "Удалим строку в конце массива: " << endl << endl;
	int** buffer = new int* [rows - 1]{}; // создаём указатель на массив указателей, который короче исходного на один и инициализируем его нулями

	for (int i = 0; i < rows - 1; i++) // копируем значения из исходного массива в буферный соответственно
	{
		buffer[i] = arr[i];
	}

	delete[] arr[rows - 1];
	delete[] arr; // затем значение массива указателей (указатели на область памяти)

	arr = buffer; // за

	rows--;
	return arr;
}

int** Pop_Col_Back(int** arr, const int rows, int& cols)
{
	cout << "Удалим строку в конце массива: " << endl << endl;
	int** buffer = new int* [rows] {};
	for (int i = 0; i < rows; i++) // создаём строки
	{
		buffer[i] = new int[cols - 1]{};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		delete[] arr[i];
	}

	delete[] arr; // затем значение массива указателей (указатели на область памяти)

	arr = buffer; // за

	cols--;
	return arr;
}

void Pop_col_Back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1];
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols--;
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

int** Pop_Row_Front(int** arr, int& rows, const int cols) // не работает
{
	cout << "Удалим строку в начале массива: " << endl << endl;
	int** buffer = new int* [rows - 1]{}; // создаём указатель на массив указателей, который короче исходного на один и инициализируем его нулями

	for (int i = 0; i < rows; i++) // копируем значения из исходного массива в буферный соответственно
	{
		buffer[i] = arr[i + 1];
	}

	delete[] arr[0];
	delete[] arr; // затем значение массива указателей (указатели на область памяти)

	arr = buffer;

	rows--;
	return arr;
}

int** Pop_Col_Front(int** arr, const int rows, int& cols)
{
	cout << "Удалим строку в начале массива: " << endl << endl;
	int** buffer = new int* [rows] {};
	for (int i = 0; i < rows; i++) // создаём строки
	{
		buffer[i] = new int[cols - 1]{};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[i][j] = arr[i][j + 1];
		}
		delete[] arr[i];
	}

	delete[] arr; // затем значение массива указателей (указатели на область памяти)

	arr = buffer;

	cols--;
	return arr;
}

template<typename T>T* Insert(T arr[], int& n, T value, int index_value)
{
	cout << "Добавим значение по указанному индексу: " << endl;
	T* buffer = new T[n + 1]{};
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

int** Insert_Row(int** arr, int& rows, const int cols, int stroka[], int index)
{
	if (index > rows) return arr;
	cout << "Вставим строку в массив по индексу: " << index << endl << endl;
	int** buffer = new int* [rows + 1]{};

	for (int i = 0; i < index; i++) // копируем значения из исходного массива в буферный соответственно
	{
		buffer[i] = arr[i];
	}

	buffer[index] = stroka;

	for (int i = index; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows++;
	return arr;
}

int** Insert_Col(int** arr, const int rows, int& cols, int stroka[], int index)
{
	if (index > cols) return arr;
	cout << "Вставим столбец в массив по индексу: " << index << endl << endl;
	int** buffer = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols + 1]{};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < index; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		for (int j = index; j < cols; j++)
		{
			buffer[i][j + 1] = arr[i][j];
		}
		delete[] arr[i];
	}

	for (int i = 0; i < rows; i++)
	{
		buffer[i][index] = stroka[i];
	}

	delete[] arr; // затем значение массива указателей (указатели на область памяти)

	arr = buffer; // за
	cols++;
	return arr;
}

int* Erase(int arr[], int& n, int value, int index_value)
{
	cout << "Удалим значение по указанному индексу: " << endl;
	int* buffer = new int[n - 1]{};
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

int** Erase_Row(int** arr, int& rows, const int cols, int index)
{
	if (index >= rows) return arr;
	cout << "Удалим строку из массива по индексу: " << index << endl << endl;
	int** buffer = new int* [rows - 1]{};

	for (int i = 0; i < index; i++) // копируем значения из исходного массива в буферный соответственно
	{
		buffer[i] = arr[i];
	}

	for (int i = index; i < rows; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	rows--;
	return arr;
}

int** Erase_Col(int** arr, const int rows, int& cols, int index)
{
	if (index > cols) return arr;
	cout << "Удалим столбец из массива по индексу: " << index << endl << endl;
	int** buffer = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols - 1]{};
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < index; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		for (int j = index; j < cols; j++)
		{
			buffer[i][j] = arr[i][j + 1];
		}
		delete[] arr[i];
	}

	delete[] arr; // затем значение массива указателей (указатели на область памяти)

	arr = buffer; // за
	cols--;
	return arr;
}

//int* insert(int arr[], int& n, int value, int index)
//{
//	int* buffer = new int[n + 1]{};
//	for (int i = 0; i < index; i++)buffer[i] = arr[i];
//	for (int i = index; i < n; i++)buffer[i + 1] = arr[i];
//	delete[] arr;
//	buffer[index] = value;
//	n++;
//	return buffer;
//}

//int** Pop_Row_Back(int** arr, int& rows, const int cols)
//{
//int** buffer = new int* [--rows] {};
//for (int i = 0; i < rows; i++)
//{
//	buffer[i] = arr[i];
//}
//delete[] arr[rows]; // удаляем строку из памяти
//delete[] arr;
//return buffer;
//}

