//Optimization
#include<iostream>
using namespace std;
using std::cout;
using std::cin;

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(char arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(double** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(char** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);

template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T** arr, const int rows, const int cols);

template <typename T>T** Allocate(const int rows, const int cols);
template <typename T>void Clear(T** arr, const int rows);

template<typename T>T* Push_Back(T arr[], int& n, T value);
template<typename T>T** Push_Row_Back(T** arr, int& rows, const int cols); // opt
template<typename T>void Push_row_Back(T**& arr, int& rows, const int cols); // opt
template<typename T>T** Push_Col_Back(T** arr, const int rows, int& cols); // opt
template<typename T>void Push_col_Back(T** arr, const int rows, int& cols); // � ������ // opt

template<typename T>T* Push_Front(T arr[], int& n, T value);
template<typename T>T** Push_Row_Front(T** arr, int& rows, const int cols); // opt
template<typename T>void Push_row_Front(T**& arr, int& rows, const int cols); // opt
template<typename T>T** Push_Col_Front(T** arr, const int rows, int& cols); // opt
template<typename T>void Push_col_Front(T** arr, const int rows, int& cols); // opt

template<typename T>T* Pop_Back(T arr[], int& n);
template<typename T>T** Pop_Row_Back(T** arr, int& rows, const int cols); // opt
template<typename T>void Pop_row_Back(T**& arr, int& rows, const int cols); // opt
template<typename T>T** Pop_Col_Back(T** arr, const int rows, int& cols); // opt
template<typename T>void Pop_col_Back(T** arr, const int rows, int& cols); // � ������ (������ �����) // opt

template<typename T>T* Pop_Front(T arr[], int& n);
template<typename T>T** Pop_Row_Front(T** arr, int& rows, const int cols); // opt
template<typename T>void Pop_row_Front(T**& arr, int& rows, const int cols); // opt
template<typename T>T** Pop_Col_Front(T** arr, const int rows, int& cols); // opt
template<typename T>void Pop_col_Front(T** arr, const int rows, int& cols); // opt

template<typename T>T* Insert(T arr[], int& n, T value, int index_value);
template<typename T>T** Insert_Row(T** arr, int& rows, const int cols, int index);
template<typename T>void Insert_row(T**& arr, int& rows, const int cols, int index);
template<typename T>T** Insert_Col(T** arr, const int rows, int& cols, int index);
template<typename T>void Insert_col(T** arr, const int rows, int& cols, int index);

template<typename T>T* Erase(T arr[], int& n, T value, int index_value);
template<typename T>T** Erase_Row(T** arr, int& rows, const int cols, int index);
template<typename T>void Erase_row(T**& arr, int& rows, const int cols, int index);
template<typename T>T** Erase_Col(T** arr, const int rows, int& cols, int index);
template<typename T>void Erase_col(T** arr, const int rows, int& cols, int index);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	//cout << int() << endl; // ������� �������� �� ��������� ��� ���� ������ 'int'
	setlocale(LC_ALL, "Russian");
#ifdef DYNAMIC_MEMORY_1
	int n; // ������ �������
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n] {}; //Heap

	//���������� � ��������� ������� �����
	FillRand(arr, n);
	Print(arr, n);
	cout << endl;

	int value;
	int index_value;
	cout << "������� ����������� �������� � ������: "; cin >> value;
	cout << "������� ������ ������������/���������� �������� (�� 0 �� " << n - 1 << "): "; cin >> index_value;

	//TODO:
	//�������� �������� � ����� �������
#ifdef ONE
	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	//1) ������ �������� ������ ������� �������:
	int* buffer = new int[n + 1]{};
	//2) ��������� ��� �������� �� ��������� ������� � ��������.
	//�������� �������� ������ � �������� ��������������
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3) ������� �������� ������:
	delete[] arr;
	//4) ��������� ������ ������ �� �����
	arr = buffer;
	//5) ������ ����� ����� �����, ����� �������� �������� � ����� �������,
	// ��������� � ����� ������� �������� �������, � ������� ����� ��������� ��������:
	arr[n] = value;
	//6) ����� ���������� �������� � ������, ���������� ��� ��������� ������������� �� 1:
	n++;
#endif ONE

	arr = Erase(arr, n, value, index_value);
	Print(arr, n);

	delete[] arr;

#endif DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows; // ���������� �����
	int cols; // ���������� ��������� ������
	cout << "������� ��������� ����� (rows): "; cin >> rows;
	cout << "������� ��������� ��������� ������ (cols): "; cin >> cols;
	////////// ���������� ���������� ������������� ������� //////////

	int** arr = Allocate<int>(rows, cols);
	//1) ������ ������ ���������� 
	//int** arr = new int* [rows] {};
	////2) ������ ������
	//for (int i = 0; i < rows; i++)
	//{
	//	arr[i] = new int[cols] {};
	//}
	//cout << "������ ������, ������ ����� ��������� ������";
	////////// ������������� ���������� ������������� ������� //////////
	cout << endl;
	//system("PAUSE");
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << endl;

	int index;

	cout << endl;
	cout << "������� ������ �����������/��������� ������: (�� 0 �� " << rows << ") ��� ������ ������������/��������� �������: (�� 0 �� " << cols << ") "; cin >> index;
	cout << endl << endl;

	//arr = Push_Row_Back(arr, rows, cols);
	//Push_row_Back(arr, rows, cols);
	//arr = Push_Col_Back(arr, rows, cols);
	//Push_col_Back(arr, rows, cols);

	//arr = Push_Row_Front(arr, rows, cols);
	//Push_row_Front(arr, rows, cols);
	//arr = Push_Col_Front(arr, rows, cols);
	//Push_col_Front(arr, rows, cols);

	//arr = Pop_Row_Back(arr, rows, cols);
	//Pop_row_Back(arr, rows, cols);
	//arr = Pop_Col_Back(arr, rows, cols);
	//Pop_col_Back(arr, rows, cols);

	//arr = Pop_Row_Front(arr, rows, cols);
	//Pop_row_Front(arr, rows, cols);
	//arr = Pop_Col_Front(arr, rows, cols);
	//Pop_col_Front(arr, rows, cols);

	//arr = Insert_Row(arr, rows, cols, index);
	//Insert_row(arr, rows, cols, index);
	//arr = Insert_Col(arr, rows, cols, index);
	//Insert_col(arr, rows, cols, index);

	//arr = Erase_Row(arr, rows, cols, index);
	//Erase_row(arr, rows, cols, index);
	//arr = Erase_Col(arr, rows, cols, index);
	//Erase_col(arr, rows, cols, index);

	//cout << "������ ���������" << endl;
	//FillRand(arr[rows - 1], cols, 200, 1000);

	Print(arr, rows, cols);
	cout << endl;

	////////// �������� ���������� ������������� ������� //////////
	//1) ������� ������
	//for (int i = 0; i < rows; i++)
	//{
	//	delete[] arr[i];
	//}
	////2) ������� ������ ����������
	//delete[] arr;

	Clear(arr, rows);

#endif DYNAMIC_MEMORY_2
}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		//��������� ���������� ���������� � �������� �������������:
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
	}
}

void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < n; i++)
	{
		//��������� ���������� ���������� � �������� �������������:
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
		*(arr + i) /= 100;
	}
}

void FillRand(char arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		//��������� ���������� ���������� � �������� �������������:
		*(arr + i) = rand();
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

void FillRand(double** arr, const int rows, const int cols, int minRand, int maxRand)
{
	minRand = 100;
	maxRand = 100;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
			arr[i][j] /= 100;
		}
	}
}

void FillRand(char** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand();
		}
	}
}

template<typename T>void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//��� �� ����� �������� ��������������[]:
		cout << arr[i] << "\t";
	}
}

template<typename T>void Print(T** arr, const int rows, const int cols)
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

template<typename T>T** Allocate(int const rows, int const cols)
{
	T** arr = new T * [rows] {};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols]{};
	}
	return arr;
}

template<typename T>void Clear(T** arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

template<typename T>T* Push_Back(T arr[], int& n, T value)
{
	cout << "������� �������� � ����� �������: " << endl;
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

template<typename T>T** Push_Row_Back(T** arr, int& rows, const int cols)
{
	cout << "������� ������ � ����� �������: " << endl << endl;
#ifdef FULL_CODE
	T** buffer = new T * [rows + 1]{}; // ������ ��������� �� ������ ����������, ������� ������� ��������� �� ���� � �������������� ��� ������

	buffer[rows] = new T[cols]{}; //� ��������� ������ ������� ���������� ���������� ��������� �� ����������� ������

	for (int i = 0; i < rows; i++) // �������� �������� �� ��������� ������� � �������� ��������������
	{
		buffer[i] = arr[i];
	}

	delete[] arr; // ����� �������� ������� ���������� (��������� �� ������� ������)

	arr = buffer; // ��

	rows++;
	return arr;
#endif // FULL_CODE

	return Push_Back(arr, rows, new T[cols]{});
}

template<typename T>void Push_row_Back(T**& arr, int& rows, const int cols)
{
	cout << "������� ������ � ����� �������: " << endl << endl;
#ifdef FULL_CODE
	T** buffer = new T * [rows + 1]{}; // ������ ��������� �� ������ ����������, ������� ������� ��������� �� ���� � �������������� ��� ������

	buffer[rows] = new T[cols]{}; //� ��������� ������ ������� ���������� ���������� ��������� �� ����������� ������

	for (int i = 0; i < rows; i++) // �������� �������� �� ��������� ������� � �������� ��������������
	{
		buffer[i] = arr[i];
	}

	delete[] arr; // ����� �������� ������� ���������� (��������� �� ������� ������)

	arr = buffer; // ��

	rows++;
#endif // FULL_CODE

	arr = Push_Back(arr, rows, new T[cols]{});
}

template<typename T>T** Push_Col_Back(T** arr, const int rows, int& cols)
{
	cout << "������� ������� � ����� �������: " << endl << endl;
	for (int i = 0; i < rows; i++) 
	{
		/*T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;*/
		arr[i] = Push_Back(arr[i], cols, T());
		cols--;
	}

	cols++;
	return arr;
}

template<typename T>void Push_col_Back(T** arr, const int rows, int& cols)
{
	cout << "������� ������� � ����� �������: " << endl << endl;
	for (int i = 0; i < rows; i++)
	{
		/*T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;*/
		arr[i] = Push_Back(arr[i], cols, T());
		cols--;
	}
	cols++;
}

template<typename T>T* Push_Front(T arr[], int& n, T value)
{
	cout << "������� �������� � ������ �������: " << endl;
	T* buffer = new T[n + 1]{};
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

template<typename T>T** Push_Row_Front(T** arr, int& rows, const int cols)
{
	cout << "������� ������ � ������ �������: " << endl << endl;
#ifdef FULL_CODE
	T** buffer = new T * [rows + 1]{}; // ������ ��������� �� ������ ����������, ������� ������� ��������� �� ���� � �������������� ��� ������

	buffer[0] = new T[cols]{}; //� ������ ������ ������� ���������� ���������� ��������� �� ����������� ������

	for (int i = 0; i < rows; i++) // �������� �������� �� ��������� ������� � �������� ��������������
	{
		buffer[i + 1] = arr[i];
	}

	delete[] arr; // ����� �������� ������� ���������� (��������� �� ������� ������)

	arr = buffer; // ��

	rows++;
	return arr;
#endif // FULL_CODE

	return Push_Front(arr, rows, new T[cols]{});

}

template<typename T>void Push_row_Front(T**& arr, int& rows, const int cols)
{
	cout << "������� ������ � ������ �������: " << endl << endl;
#ifdef FULL_CODE
	T** buffer = new T * [rows + 1]{}; // ������ ��������� �� ������ ����������, ������� ������� ��������� �� ���� � �������������� ��� ������

	buffer[0] = new T[cols]{}; //� ������ ������ ������� ���������� ���������� ��������� �� ����������� ������

	for (int i = 0; i < rows; i++) // �������� �������� �� ��������� ������� � �������� ��������������
	{
		buffer[i + 1] = arr[i];
	}

	delete[] arr; // ����� �������� ������� ���������� (��������� �� ������� ������)

	arr = buffer; // ��

	rows++;
#endif // FULL_CODE

	arr =  Push_Front(arr, rows, new T[cols]{});
	
}

template<typename T>T** Push_Col_Front(T** arr, const int rows, int& cols)
{
	cout << "������� ������� � ������ �������: " << endl << endl;
	for (int i = 0; i < rows; i++) // ������ ������
	{
		/*T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;*/
		arr[i] = Push_Front(arr[i], cols, T());
		cols--;
	}
		
	cols++;
	return arr;
}

template<typename T>void Push_col_Front(T** arr, const int rows, int& cols)
{
	cout << "������� ������� � ������ �������: " << endl << endl;
	for (int i = 0; i < rows; i++)
	{
		/*T* buffer = new T[cols + 1]{};
		for (int j = 0; j < cols + 1; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;*/
		arr[i] = Push_Front(arr[i], cols, T());
		cols--;
	}
	cols++;
}

template<typename T>T* Pop_Back(T arr[], int& n)
{
	cout << "������ ��������� ������� �������: " << endl;
	T* buffer = new T[n - 1]{};
	for (int i = 0; i < n - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}

template<typename T>T** Pop_Row_Back(T** arr, int& rows, const int cols)
{
	cout << "������ ������ � ����� �������: " << endl << endl;
#ifdef FULL_CODE
	T** buffer = new T * [--rows]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr[rows]; // ������� ������ �� ������
	delete[] arr;
	return buffer;
#endif // FULL_CODE

	delete[] arr[rows - 1];			// ������� ��������� ������ �� ������
	return Pop_Back(arr, rows);		// ���������� ��������������� ������ ����������
}

template<typename T>void Pop_row_Back(T**& arr, int& rows, const int cols)
{
	cout << "������ ������ � ����� �������: " << endl << endl;
#ifdef FULL_CODE
	T** buffer = new T * [--rows]{};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr[rows]; // ������� ������ �� ������
	//delete[] arr; // ? ����� �� ������� ������ ������ ���������
	arr = buffer; // ?    
#endif // FULL_CODE

	delete[] arr[rows - 1];			
	arr = Pop_Back(arr, rows);	
}

template<typename T>T** Pop_Col_Back(T** arr, const int rows, int& cols)
{
	cout << "������ ������� � ����� �������: " << endl << endl;
	for (int i = 0; i < rows; i++) // ������ ������
	{
		//T* buffer = new T[cols - 1]{};
		//for (int j = 0; j < cols - 1; j++)
		//{
		//	buffer[j] = arr[i][j];
		//}
		//delete[] arr[i];
		//arr[i] = buffer; // ��
		arr[i] = Pop_Back(arr[i], cols);
		cols++;
	}

	cols--;
	return arr;
}

template<typename T>void Pop_col_Back(T** arr, const int rows, int& cols)
{
	cout << "������ ������� � ����� �������: " << endl << endl;
	for (int i = 0; i < rows; i++)
	{
		/*T* buffer = new T[cols - 1];
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;*/
		arr[i] = Pop_Back(arr[i], cols);
		cols++;
	}
	cols--;
}

template<typename T>T* Pop_Front(T arr[], int& n)
{
	cout << "������ ������ ������� �������: " << endl;
	T* buffer = new T[n - 1]{};
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}

template<typename T>T** Pop_Row_Front(T** arr, int& rows, const int cols) // �� ��������
{
	cout << "������ ������ � ������ �������: " << endl << endl;
#ifdef FULL_CODE
	T** buffer = new T * [rows - 1]{}; // ������ ��������� �� ������ ����������, ������� ������ ��������� �� ���� � �������������� ��� ������

	for (int i = 0; i < rows; i++) // �������� �������� �� ��������� ������� � �������� ��������������
	{
		buffer[i] = arr[i + 1];
	}

	delete[] arr[0];
	delete[] arr; // ����� �������� ������� ���������� (��������� �� ������� ������)

	arr = buffer;

	rows--;
	return arr;
#endif // FULL_CODE

	delete[] arr[0];			// ������� ��������� ������ �� ������
	return Pop_Front(arr, rows);		// ���������� ��������������� ������ ����������

}

template<typename T>void Pop_row_Front(T**& arr, int& rows, const int cols)
{
	cout << "������ ������ � ������ �������: " << endl << endl;
#ifdef FULL_CODE
	T** buffer = new T * [rows - 1]{}; // ������ ��������� �� ������ ����������, ������� ������ ��������� �� ���� � �������������� ��� ������
	for (int i = 0; i < rows; i++) // �������� �������� �� ��������� ������� � �������� ��������������
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr[0];
	delete[] arr; // ����� �������� ������� ���������� (��������� �� ������� ������)
	arr = buffer;
	rows--;
#endif // FULL_CODE

	delete[] arr[0];			// ������� ��������� ������ �� ������
	arr = Pop_Front(arr, rows);		// ���������� ��������������� ������ ����������
}

template<typename T>T** Pop_Col_Front(T** arr, const int rows, int& cols)
{
	cout << "������ ������� � ������ �������: " << endl << endl;
	for (int i = 0; i < rows; i++) // ������ ������
	{
		/*T* buffer = new T[cols - 1]{};
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;*/
		arr[i] = Pop_Front(arr[i], cols);
		cols++;
	}
	
	cols--;
	return arr;
}

template<typename T>void Pop_col_Front(T** arr, const int rows, int& cols)
{
	cout << "������ ������� � ������ �������: " << endl << endl;
	for (int i = 0; i < rows; i++)
	{
		/*T* buffer = new T[cols - 1];
		for (int j = 0; j < cols - 1; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;*/
		arr[i] = Pop_Front(arr[i], cols);
		cols++;
	}
	cols--;
}

template<typename T>T* Insert(T arr[], int& n, T value, int index_value)
{
	cout << "������� �������� �� ���������� �������: " << endl;
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

template<typename T>T** Insert_Row(T** arr, int& rows, const int cols, int index)
{
	if (index > rows) return arr;
	cout << "������� ������ � ������ �� �������: " << index << endl << endl;
	T** buffer = new T * [rows + 1]{};

	for (int i = 0; i < index; i++) // �������� �������� �� ��������� ������� � �������� ��������������
	{
		buffer[i] = arr[i];
	}

	buffer[index] = new T[cols]{};

	for (int i = index; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows++;
	return arr;
}

template<typename T>void Insert_row(T**& arr, int& rows, const int cols, int index)
{
	//if (index > rows) return arr;
	cout << "������� ������ � ������ �� �������: " << index << endl << endl;
	T** buffer = new T * [rows + 1]{};

	for (int i = 0; i < index; i++) // �������� �������� �� ��������� ������� � �������� ��������������
	{
		buffer[i] = arr[i];
	}

	buffer[index] = new T[cols]{};

	for (int i = index; i < rows; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	rows++;
	//return arr;
}

template<typename T>T** Insert_Col(T** arr, const int rows, int& cols, int index)
{
	if (index > cols) return arr;
	cout << "������� ������� � ������ �� �������: " << index << endl << endl;
	T** buffer = new T * [rows] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new T[cols + 1]{};
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

	delete[] arr; // ����� �������� ������� ���������� (��������� �� ������� ������)

	arr = buffer; // ��
	cols++;
	return arr;
}

template<typename T>void Insert_col(T** arr, const int rows, int& cols, int index)
{
	//if (index > cols) return arr;
	cout << "������� ������� � ������ �� �������: " << index << endl << endl;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols + 1]{};
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = index; j < cols; j++)
		{
			buffer[j + 1] = arr[i][j];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}

	//delete[] arr; // ����� �������� ������� ���������� (��������� �� ������� ������)
	//arr = buffer; // ��
	cols++;
	//return arr;
}

template<typename T>T* Erase(T arr[], int& n, T value, int index_value)
{
	cout << "������ �������� �� ���������� �������: " << endl;
	T* buffer = new T[n - 1]{};
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

template<typename T>T** Erase_Row(T** arr, int& rows, const int cols, int index)
{
	if (index >= rows) return arr;
	cout << "������ ������ �� ������� �� �������: " << index << endl << endl;
	T** buffer = new T * [rows - 1]{};

	for (int i = 0; i < index; i++) // �������� �������� �� ��������� ������� � �������� ��������������
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

template<typename T>void Erase_row(T**& arr, int& rows, const int cols, int index)
{
	//if (index >= rows) return arr;
	cout << "������ ������ �� ������� �� �������: " << index << endl << endl;
	T** buffer = new T * [rows - 1]{};

	for (int i = 0; i < index; i++) // �������� �������� �� ��������� ������� � �������� ��������������
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
	//return arr;
}

template<typename T>T** Erase_Col(T** arr, const int rows, int& cols, int index)
{
	if (index > cols) return arr;
	cout << "������ ������� �� ������� �� �������: " << index << endl << endl;
	T** buffer = new T * [rows] {};
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new T[cols - 1]{};
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

	delete[] arr; // ����� �������� ������� ���������� (��������� �� ������� ������)

	arr = buffer; // ��
	cols--;
	return arr;
}

template<typename T>void Erase_col(T** arr, const int rows, int& cols, int index)
{
	cout << "������ ������� �� ������� �� �������: " << index << endl << endl;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1]{};
		for (int j = 0; j < index; j++)
		{
			buffer[j] = arr[i][j];
		}
		for (int j = index; j < cols; j++)
		{
			buffer[j] = arr[i][j + 1];
		}
		delete[] arr[i];
		arr[i] = buffer;
	}

	//delete[] arr; // ����� �������� ������� ���������� (��������� �� ������� ������)
	//arr = buffer; // ��
	cols--;
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



