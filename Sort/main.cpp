#include <iostream>
#include <conio.h>
#include <chrono>
#include <iomanip>

#include "SORT.h"

using namespace std;



void test(int arra[]);
void swapTest(int *xp, int *yp);

void showArray(int arra[]);
void showArray2(int *arra);

void createArray(int arra[]);
void createArray2(int *arra);

void copyOfArray(int arra[]);


int main()
{
	Sort<int> sort;
	int arr[8];
	int *arr2 = new int[8];

	createArray(arr);
	showArray(arr);
	sort.bubleSort(arr);

	createArray(arr);
	showArray(arr);
	sort.cocktailSort(arr);

	createArray(arr2);
	showArray2(arr2);
	sort.insertionSort(arr2);

	createArray(arr);
	showArray(arr);
	sort.gnomeSort(arr);

	delete[] arr2;
	_getch();
	return 0;
}

void test(int arra[])
{
}

void swapTest(int * xp, int * yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void showArray(int arra[])
{
	cout << "_________________________________________________" << endl;
	cout << "New array: " << endl;
	for (int i = 0; i < 8; ++i)
	{
		cout  << arra[i] << "\t";
	}
	cout << endl << "_________________________________________________" ;
}

void showArray2(int * arra)
{
	cout << "_________________________________________________" << endl;
	cout << "New array: " << endl;
	for (int i = 0; i < 8; ++i)
	{
		cout << setw(2) << arra[i] << "\t";
	}
	cout << endl << "_________________________________________________";
}

void createArray(int arra[])
{
	for (int i = 0; i < 8; ++i)
	{
		arra[i] = rand() % 45;
	}
}

void createArray2(int *arra)
{
	for (int i = 0; i < 8; ++i)
	{
		arra[i] = rand() % 45;
	}
}

void copyOfArray(int arra[])
{
	int arrCopy[8];
	for (int i = 0; i < 8; ++i)
	{
		arrCopy[i] = arra[i];
	}
}

