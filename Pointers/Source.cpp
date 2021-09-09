#include<iostream>
using namespace std;
using std::cout;

//#define POINTERS_BASICS
#define POINTERS_AND_ARRAYS

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a;
	cout << a << endl; // ����� �������� ���������� '�' �� �����.
	cout << &a << endl; // ������ ������ ���������� '�' ����� ��� ������.
	cout << pa << endl; // ����� ������ ���������� '�', ����������� � ��������� '��'.
	cout << *pa << endl; // ������������� ��������� 'pa' � ��������� �������� �� ������.

	int* pb; // ��������� ��������� 'pb', �� ���� ��� �� � ���� �������
	//....
	int b = 3;
	//l-value = r-value;
	pb = &b;
	//(int) = (int*)
	cout << b << endl;
	cout << &b << endl;
	cout << *pb << endl;
	//int - int
	//int* - ��������� �� int
	//double - double
	//double* - ��������� �� double  
#endif // POINTERS_BASICS

#ifdef POINTERS_AND_ARRAYS
	const int n = 5;
	int arr[n] = {3,5,8,13,21};
	cout << arr << endl;
	cout << *arr << endl;

	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;

#endif POINTERS_AND_ARRAYS

}