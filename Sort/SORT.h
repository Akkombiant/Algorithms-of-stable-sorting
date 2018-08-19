#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <chrono>
#include <iomanip>


using namespace std;

template <typename T>
class Sort
{
public:
	Sort();

	void bubleSort(T iArr[]);
	void cocktailSort(T iArr[]);
	void insertionSort(T *iArr);
	void gnomeSort(T iArr[]);


	~Sort();
protected:
	void swap(int *xp, int *yp);
	
private:
	unsigned int countOfIterat;
};


template<typename T>
Sort<T>::Sort() : countOfIterat(0)
{
}

template<typename T>
void Sort<T>::bubleSort(T iArr[])
{
	auto start = chrono::high_resolution_clock::now();
	auto stop = start;

	start = chrono::high_resolution_clock::now();

	bool swapped;
	for (int i = 0; i < 8 - 1; ++i)
	{
		swapped = false;
		for (int j = 0; j < 8 - i - 1; ++j)
		{
			if (iArr[j] > iArr[j + 1])
			{
				swap(&iArr[j], &iArr[j + 1]);
				swapped = true;
			}
			++countOfIterat;
		}
		if (swapped == false)
		{
			break;
		}
	}
	cout << endl << "_________________________________________________" << endl;
	cout << "Buble Sorted: \n";
	for (int i = 0; i < 8; ++i)
	{
		cout << iArr[i] << "\t";
	}
	cout << endl;

	stop = chrono::high_resolution_clock::now();
	cout << "\nTime: " << chrono::duration_cast<chrono::milliseconds>(stop - start).count() << " milliseconds\n";

	cout << "Count of Iterat: " <<countOfIterat << endl;
	countOfIterat = 0;

	cout << "_________________________________________________" << endl
		<< "=================================================" << endl;
}

template<typename T>
void Sort<T>::cocktailSort(T iArr[])
{
	auto start = chrono::high_resolution_clock::now();
	auto stop = start;

	start = chrono::high_resolution_clock::now();

	for (int i = 0; i < 8 - 1; ++i)
	{
		for (int j = 0; j < 8 - i - 1; ++j)
		{
			if (iArr[j] > iArr[j + 1])
			{
				swap(&iArr[j], &iArr[j + 1]);
			}
			++countOfIterat;
		}
		for (int j = 8 - 1; j > 0 + i + 1; --j)
		{
			if (iArr[j - 1] > iArr[j])
			{
				swap(&iArr[j - 1], &iArr[j]);
			}
			++countOfIterat;
		}
	}

	cout << endl << "_________________________________________________" << endl;
	cout << "Cock Tail`s Sorted: \n";
	for (int i = 0; i < 8; ++i)
	{
		cout << iArr[i] << "\t";
	}
	cout << endl;

	stop = chrono::high_resolution_clock::now();
	cout << "\nTime: " << chrono::duration_cast<chrono::milliseconds>(stop - start).count() << " milliseconds\n";

	cout << "Count of Iterat: " << countOfIterat << endl;
	countOfIterat = 0;

	cout << "_________________________________________________" << endl
		<< "=================================================" << endl;
}

template<typename T>
void Sort<T>::insertionSort(T *iArr)
{
	auto start = chrono::high_resolution_clock::now();
	auto stop = start;

	start = chrono::high_resolution_clock::now();

	int temp;
	int	item; 

	for (int i = 1; i < 8; ++i)
	{
		temp = iArr[i];
		item = i - 1;
		while (item >= 0 && iArr[item] > temp) 
		{
			iArr[item + 1] = iArr[item]; 
			iArr[item] = temp;
			item--;

			++countOfIterat;
		}
	}

	cout << endl << "_________________________________________________" << endl;
	cout << "Insert Sorted: \n";
	for (int i = 0; i < 8; ++i)
	{
		cout <<setw(2) << iArr[i] << "\t";
	}
	cout << endl;

	stop = chrono::high_resolution_clock::now();
	cout << "\nTime: " << chrono::duration_cast<chrono::milliseconds>(stop - start).count() << " milliseconds\n";

	cout << "Count of Iterat: " << countOfIterat << endl;
	countOfIterat = 0;

	cout << "_________________________________________________" << endl
		<< "=================================================" << endl;
}

template<typename T>
void Sort<T>::gnomeSort(T iArr[])
{

	auto start = chrono::high_resolution_clock::now();
	auto stop = start;

	start = chrono::high_resolution_clock::now();

	int i = 0;
	int j = 0;
	while (i < 8)
	{
		if (iArr[i - 1] <= iArr[i])
		{
			i = j;
			++j;
			++countOfIterat;
		}
		else 
		{
			int t = iArr[i];
			iArr[i] = iArr[i - 1];
			iArr[i - 1] = t;

			--i;

			if (i == 0)
			{
				i = j;
				++j;
			}
			++countOfIterat;
		}
	}
	cout << endl << "_________________________________________________" << endl;
	cout << "Gnome Sort: \n";
	for (int i = 0; i < 8; ++i)
	{
		cout << iArr[i] << "\t";
	}
	cout << endl;

	stop = chrono::high_resolution_clock::now();
	cout << "\nTime: " << chrono::duration_cast<chrono::milliseconds>(stop - start).count() << " milliseconds\n";

	cout << "Count of Iterat: " << countOfIterat << endl;
	countOfIterat = 0;

	cout << "_________________________________________________" << endl
		<< "=================================================" << endl;
}

template<typename T>
Sort<T>::~Sort()
{
}

template<typename T>
void Sort<T>::swap(int * xp, int * yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

#endif