#include<iostream>
using namespace std;
using std:: cin;
using std:: cout;
using std:: endl;

#define tab "\t"
#define delimiter "\n----------------\n"

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int rows, const int cols);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);
int* Push_Back(int arr[], int& n, int value);
int* Push_Front(int arr[], int& n, int value);
int* Insert(int arr[], int& n, int value, int index);
int* Pop_back(int arr[], int& n);
int* Pop_front(int arr[], int& n);
int* Erase(int arr[], int& n, int index);


int** Allocate(const int rows, const int cols);
void Clear(int** arr, const int rows);
int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows, const int cols);
int** pop_row_back(int** arr, int& n, const int cols);
void push_coll_back(int** arr, const int rows, int& cols);
void pop_coll_back(int** arr, const int rows, int& cols);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2
void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
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

	Print(arr = Pop_back(arr, n), n);
	Print(arr = Pop_front(arr, n), n);

	cout << "Введите индекс, откуда нужно убрать значение: "; cin >> index;
	arr = Erase(arr, n, index);
	Print(arr, n);

	delete[] arr;
#endif
#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	int** arr = Allocate(rows, cols); // создаем массив указателей

	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int [cols] {};
	}

	
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter;

	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter;

	Print(arr = pop_row_back(arr, rows, cols), rows, cols);
	cout << delimiter;

	push_coll_back(arr, rows, cols);
	Print(arr, rows, cols);
	cout << delimiter;

	pop_coll_back(arr, rows, cols);
	Print(arr, rows, cols);

	Clear(arr, rows);
#endif
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		// Обращение к элементам массива через арифметику и оператор разименования
		*(arr + i) = rand() % 100;
	}
}

void FillRand(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
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

void Print(int** arr, const int rows, const int cols)
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cout << arr[i][j] << tab;
			}
			cout << endl;
		}
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
		buffer[i + 1] = arr[i];
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
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;

	return buffer;
}

int* Erase(int arr[], int& n, int index)
{
	int* buffer = new int[--n] {};
	/*for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < n; i++)buffer[i] = arr[i + 1];
	*/
	for (int i = 0; i < n; i++)
	{
		/*if (i < index)buffer[i] = arr[i];
		else
		{
			buffer[i] = arr[i + 1];
		}*/
		//i < index ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
		//buffer[i] = i < index ? arr[i] : arr[i + 1];
		buffer[i] = arr[i < index ? i : i + 1];
	}
	delete[] arr;

	return buffer;
}

int** Allocate(const int rows, const int cols)
{
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	return arr;
}


void Clear(int** arr, const int rows)
{
	delete[] arr;
}

int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int*[rows+1] {};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	
	delete[] arr;
	buffer[rows] = new int[cols] {};
	rows++;
	return buffer;
}

int** pop_row_back(int** arr, int& rows, const int cols)
{
	delete[] arr[rows - 1];
	int** buffer = new int* [--rows] {};
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}

void push_coll_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols + 1] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

void pop_coll_back(int** arr, const int rows, int& cols)
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
}

int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1] {};
	for (int i = 0; i < rows; i++)buffer[i+1] = arr[i];

	delete[] arr;
	buffer[rows] = new int[cols] {};
	rows++;
	return buffer;
}
