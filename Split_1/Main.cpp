#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n----------------\n"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);

	int even_count = 0;
	int odd_count = 0;
	for (int i = 0; i < n; i++)
	{
		arr[i] % 2 ? odd_count++ : even_count++;
	}

	int* even_arr = new int[even_count];
	int* odd_arr = new int[odd_count];

	for (int i = 0, j=0, k=0; i < n; i++)
	{
		/*if (arr[i] % 2 == 0)
		{
			even_arr[j] = arr[i];
			j++;
		}
		else
		{
			odd_arr[k] = arr[i];
			k++;
		}*/
		arr[i] % 2 == 0 ? even_arr[j++] = arr[i] : odd_arr [k++] = arr[i];
	}

	Print(even_arr, even_count);
	Print(odd_arr, odd_count);

	delete[] odd_arr;
	delete[] even_arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		// Обращение к элементам массива через арифметику и оператор разименования
		arr[i] = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//Обращение к элекментам через оператор индексирования
		cout << arr[i] << tab;
	}
	cout << endl;
}