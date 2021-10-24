#include"Memory.h"

int** Allocate(int const rows, int const cols)
{
	int** arr = new int* [rows] {};
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
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

int* Push_Back(int arr[], int& n, int value)
{
	cout << "������� �������� � ����� �������: " << endl;
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

int** Push_Row_Back(int** arr, int& rows, const int cols, int stroka[])
{
	cout << "������� ������ � ����� �������: " << endl << endl;
	int** buffer = new int* [rows + 1]{}; // ������ ��������� �� ������ ����������, ������� ������� ��������� �� ���� � �������������� ��� ������

	buffer[rows] = stroka; //� ��������� ������ ������� ���������� ���������� ��������� �� ����������� ������

	for (int i = 0; i < rows; i++) // �������� �������� �� ��������� ������� � �������� ��������������
	{
		buffer[i] = arr[i];
	}

	delete[] arr; // ����� �������� ������� ���������� (��������� �� ������� ������)

	arr = buffer; // ��

	rows++;
	return arr;
}

int** Push_Col_Back(int** arr, const int rows, int& cols, int stroka[])
{
	cout << "������� ������� � ����� �������: " << endl << endl;
	int** buffer = new int* [rows] {}; // ������ ��������� �� ������ ����������, ������� ������� ��������� �� ���� � �������������� ��� ������
	for (int i = 0; i < rows; i++) // ������ ������
	{
		buffer[i] = new int[cols + 1]{};// ��� ������� ��������� ����������� ������� ������ ������ cols, � ������� ����� ���������� int'� � ���� �������������� ��� ������
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

	delete[] arr; // ����� �������� ������� ���������� (��������� �� ������� ������)

	arr = buffer; // ��

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
	cout << "������� �������� � ������ �������: " << endl;
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
	cout << "������� ������ � ������ �������: " << endl << endl;
	int** buffer = new int* [rows + 1]{}; // ������ ��������� �� ������ ����������, ������� ������� ��������� �� ���� � �������������� ��� ������

	buffer[0] = stroka; //� ������ ������ ������� ���������� ���������� ��������� �� ����������� ������

	for (int i = 0; i < rows; i++) // �������� �������� �� ��������� ������� � �������� ��������������
	{
		buffer[i + 1] = arr[i];
	}

	delete[] arr; // ����� �������� ������� ���������� (��������� �� ������� ������)

	arr = buffer; // ��

	rows++;
	return arr;
}

int** Push_Col_Front(int** arr, const int rows, int& cols, int stroka[])
{
	cout << "������� ������� � ������ �������: " << endl << endl;
	int** buffer = new int* [rows] {};
	for (int i = 0; i < rows; i++) // ������ ������
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

	delete[] arr; // ����� �������� ������� ���������� (��������� �� ������� ������)

	arr = buffer; // ��

	cols++;
	return arr;
}

int* Pop_Back(int arr[], int& n)
{
	cout << "������ ��������� ������� �������: " << endl;
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
	cout << "������ ������ � ����� �������: " << endl << endl;
	int** buffer = new int* [rows - 1]{}; // ������ ��������� �� ������ ����������, ������� ������ ��������� �� ���� � �������������� ��� ������

	for (int i = 0; i < rows - 1; i++) // �������� �������� �� ��������� ������� � �������� ��������������
	{
		buffer[i] = arr[i];
	}

	delete[] arr[rows - 1];
	delete[] arr; // ����� �������� ������� ���������� (��������� �� ������� ������)

	arr = buffer; // ��

	rows--;
	return arr;
}

int** Pop_Col_Back(int** arr, const int rows, int& cols)
{
	cout << "������ ������ � ����� �������: " << endl << endl;
	int** buffer = new int* [rows] {};
	for (int i = 0; i < rows; i++) // ������ ������
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

	delete[] arr; // ����� �������� ������� ���������� (��������� �� ������� ������)

	arr = buffer; // ��

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
	cout << "������ ������ ������� �������: " << endl;
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

int** Pop_Row_Front(int** arr, int& rows, const int cols) // �� ��������
{
	cout << "������ ������ � ������ �������: " << endl << endl;
	int** buffer = new int* [rows - 1]{}; // ������ ��������� �� ������ ����������, ������� ������ ��������� �� ���� � �������������� ��� ������

	for (int i = 0; i < rows; i++) // �������� �������� �� ��������� ������� � �������� ��������������
	{
		buffer[i] = arr[i + 1];
	}

	delete[] arr[0];
	delete[] arr; // ����� �������� ������� ���������� (��������� �� ������� ������)

	arr = buffer;

	rows--;
	return arr;
}

int** Pop_Col_Front(int** arr, const int rows, int& cols)
{
	cout << "������ ������ � ������ �������: " << endl << endl;
	int** buffer = new int* [rows] {};
	for (int i = 0; i < rows; i++) // ������ ������
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

	delete[] arr; // ����� �������� ������� ���������� (��������� �� ������� ������)

	arr = buffer;

	cols--;
	return arr;
}

int* Insert(int arr[], int& n, int value, int index_value)
{
	cout << "������� �������� �� ���������� �������: " << endl;
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

int** Insert_Row(int** arr, int& rows, const int cols, int stroka[], int index)
{
	if (index > rows) return arr;
	cout << "������� ������ � ������ �� �������: " << index << endl << endl;
	int** buffer = new int* [rows + 1]{};

	for (int i = 0; i < index; i++) // �������� �������� �� ��������� ������� � �������� ��������������
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
	cout << "������� ������� � ������ �� �������: " << index << endl << endl;
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

	delete[] arr; // ����� �������� ������� ���������� (��������� �� ������� ������)

	arr = buffer; // ��
	cols++;
	return arr;
}

int* Erase(int arr[], int& n, int value, int index_value)
{
	cout << "������ �������� �� ���������� �������: " << endl;
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
	cout << "������ ������ �� ������� �� �������: " << index << endl << endl;
	int** buffer = new int* [rows - 1]{};

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

int** Erase_Col(int** arr, const int rows, int& cols, int index)
{
	if (index > cols) return arr;
	cout << "������ ������� �� ������� �� �������: " << index << endl << endl;
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

	delete[] arr; // ����� �������� ������� ���������� (��������� �� ������� ������)

	arr = buffer; // ��
	cols--;
	return arr;
}