#include <iostream>
#include <time.h>
using namespace std;

void func_gen(int** arr, int size) {

	for (int i = 0; i < size; i++)
	{

		for (int j = 0; j < size; j++)
		{
			arr[i][j] = rand() % 10;

		}
	}
}
int func_sum(int** arr, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++)
	{

		for (int j = 0; j < size; j++)
		{
			sum += arr[i][j];

		}
	}
	return sum;
}
double func_avg(int** arr, int size) {
	int sum = 0;
	int c = 0;
	double avg;
	for (int i = 0; i < size; i++)
	{

		for (int j = 0; j < size; j++)
		{
			sum += arr[i][j];
			c++;
		}
	}
	avg = sum / (double)c;
	return avg;
}
void func_show(int** arr, int size) {
	for (size_t i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}
void func_del_arr(int** arr, int size) {
	for (size_t i = 0; i < size; i++)
	{
		delete[]  arr[i];
	}
	delete[]  arr;
}
int main()
{
	srand(time(NULL));
	int size = 8;
	int** arr;
	arr = new int* [size];
	for (int i = 0; i < size; i++)
		arr[i] = new int[size];
	func_gen(arr, size);
	func_show(arr, size);
	cout << "sum this arr is = " << func_sum(arr, size) << endl;
	cout << "avg this arr is = " << func_avg(arr, size) << endl;

	func_del_arr(arr, size);
}
