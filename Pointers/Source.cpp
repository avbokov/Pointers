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
	cout << a << endl; // вывод значения переменной 'а' на экран.
	cout << &a << endl; // взятие адреса переменной 'а' прямо при выводе.
	cout << pa << endl; // вывод адреса переменной 'а', хранящегося в указателе 'ра'.
	cout << *pa << endl; // разименование указателя 'pa' и получение значения по адресу.

	int* pb; // объявляем указатель 'pb', не зная что мы в него положим
	//....
	int b = 3;
	//l-value = r-value;
	pb = &b;
	//(int) = (int*)
	cout << b << endl;
	cout << &b << endl;
	cout << *pb << endl;
	//int - int
	//int* - указатель на int
	//double - double
	//double* - указатель на double  
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