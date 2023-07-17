#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n----------------\n"

void EVEN_ODD(int source[], int size, int*& even, int& evenSize, int*& odd, int& oddSize);

void main()
{
	setlocale(LC_ALL, "");
	int n = 10;
	int* arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		// ��������� � ��������� ������� ����� ���������� � �������� �������������
		*(arr + i) = rand() % 100;
	}

	// �������� ���������� �� ������� ��� ������ � �������� �����
	int* evenArray = nullptr;
	int* oddArray = nullptr;
	int evenSize, oddSize;

	// ����������� ������ � �������� ����� � ������������ �������
	EVEN_ODD(arr, n, evenArray, evenSize, oddArray, oddSize);

	for (int i = 0; i < n; i++)
	{
		//��������� � ���������� ����� �������� ��������������
		cout << arr[i] << tab;
	}
	cout << endl;

	cout << "������ ������ �����: ";
	for (int i = 0; i < evenSize; i++) {
		std::cout << evenArray[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "������ �������� �����: ";
	for (int i = 0; i < oddSize; i++) {
		std::cout << oddArray[i] << " ";
	}
	delete[] evenArray;
	delete[] oddArray;
}

void EVEN_ODD(int source[], int size, int*& even, int& evenSize, int*& odd, int& oddSize) 
{
	// ������������ ���������� ������ � �������� ���������
	evenSize = 0;
	oddSize = 0;
	for (int i = 0; i < size; i++) {
		if (source[i] % 2 == 0) {
			evenSize++;
		}
		else {
			oddSize++;
		}
	}
	// ������� ������������ ������� ��� ������ � �������� �����
	even = new int[evenSize];
	odd = new int[oddSize];

	// ����������� ������ � �������� ����� � ��������������� �������
	int evenIndex = 0;
	int oddIndex = 0;
	for (int i = 0; i < size; i++) {
		if (source[i] % 2 == 0) {
			even[evenIndex] = source[i];
			evenIndex++;
		}
		else {
			odd[oddIndex] = source[i];
			oddIndex++;
		}
	}

}
