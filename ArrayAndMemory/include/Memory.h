#pragma once
#include<iostream>
using namespace std;

int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);

int* Push_Back(int arr[], int& n, int value);
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

int* Insert(int arr[], int& n, int value, int index_value);
int** Insert_Row(int** arr, int& rows, const int cols, int stroka[], int index);
int** Insert_Col(int** arr, const int rows, int& cols, int stroka[], int index);

int* Erase(int arr[], int& n, int value, int index_value);
int** Erase_Row(int** arr, int& rows, const int cols, int index);
int** Erase_Col(int** arr, const int rows, int& cols, int index);