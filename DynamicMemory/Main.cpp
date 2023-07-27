#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n----------------\n"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
int* Push_Back (int arr[], int& n, int value);
int* Push_Front (int arr[], int& n, int value);
int* Insert(int arr[], int& n, int value, int index);
int* Pop_back(int arr[], int& n);
int* Pop_front(int arr[], int& n);
int* Erase(int arr[], int& n, int index);


void main()
{
	setlocale(LC_ALL, "");
	int n; //Кол-во эл-ов массива
	cout << "Введите размер массива "; cin >> n;
	int* arr = new int[n];
	
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение : "; cin >> value;
	arr = Push_Back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение : "; cin >> value;
	arr = Push_Front(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение : "; cin >> value;
	int index;
	cout << "Введите индекс, куда нужно вставить значение: "; cin >> index;
	arr = Insert(arr, n, value, index);
	Print(arr, n);

	Print (arr=Pop_back(arr, n), n);
	Print (arr=Pop_front(arr, n), n);

	cout << "Введите индекс, откуда нужно убрать значение: "; cin >> index;
	arr = Erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		// Обращение к элементам массива через арифметику и оператор разименования
		*(arr + i) = rand() % 100;
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

int* Push_Back(int arr[], int& n, int value)
{


	int* buffer = new int[n + 1]; //создаем буфферный маасив
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

int* Push_Front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1]; //создаем буфферный маасив
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;
	arr = buffer;

	arr[0] = value;
	n++;
	return arr;
}

int* Insert(int arr[], int& n, int value, int index)
{
	int* buffer = new int[n + 1];
	
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < n; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	arr = buffer;
	arr[index] = value;
	n++;
	return arr;
}

int* Pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	
	return buffer;
}

int* Pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n+1; i++)
	{
		buffer[i-1] = arr[i];
	}
	delete[] arr;

	return buffer;
}

int* Erase(int arr[], int& n, int index)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		if (i != index)buffer[i] = arr[i];
	}

	delete[] arr;

	return buffer;
}