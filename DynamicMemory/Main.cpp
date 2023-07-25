#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n----------------\n"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void Push_Back (int arr[], int n, int value);
void Push_Front (int arr[], int n, int value_1);


void main()
{
	setlocale(LC_ALL, "");
	int n; //���-�� ��-�� �������
	cout << "������� ������ ������� "; cin >> n;
	int* arr = new int[n];
	
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "������� ����������� �������� : "; cin >> value;
	Push_Back(arr, n, value);

	int value_1;
	cout << "������� ����������� �������� : "; cin >> value_1;
	Push_Front(arr, n, value_1);
	
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		// ��������� � ��������� ������� ����� ���������� � �������� �������������
		*(arr + i) = rand() % 100;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//��������� � ���������� ����� �������� ��������������
		cout << arr[i] << tab;
	}
	cout << endl;
}

void Push_Back(int arr[], int n, int value)
{
	int* buffer = new int[n + 1]; //������� ��������� ������
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;

	arr[n] = value;
	n++;
	Print(arr, n);

	delete[] arr;
}

void Push_Front(int arr[], int n, int value_1)
{
	int* buffer = new int[n + 1]; //������� ��������� ������
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	arr = buffer;

	arr[0] = value_1;
	n++;
	Print(arr, n);
	delete[] arr;
}