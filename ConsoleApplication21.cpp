#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

void findMin(int** arr, int len);
void findMax(int** arr, int len);
void mainDiagonal(int** arr, int len);
void secondaryDiagonal(int** arr, int len);

void entryFile(int** arr, int size) {

    string path = "myFile.txt";
    ofstream fout;

    fout.open(path);

    if (!fout.is_open())
    {
        cout << "Error open file !";
    }
    else
    {
        cout << "Array written to file !\n";
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                fout << arr[i][j] << " ";
            }
            fout << endl;
        }
    }

    fout.close();

    ifstream fin;
    fin.open(path);

    if (!fin.is_open())
    {
        cout << "Error open file !";
    }
    else
    {
        cout << "File is open !\n\n";
        char ch;
        while (fin.get(ch))
        {
            cout << ch;
        }
        cout << endl;
    }

    fin.close();

}
void func_gen(int** arr, int size)
{

    for (int i = 0; i < size; i++)
    {

        for (int j = 0; j < size; j++)
        {
            arr[i][j] = rand() % 10;
        }
    }
}
int func_sum(int** arr, int size)
{
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
double func_avg(int** arr, int size)
{
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
void func_show(int** arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}
void func_del_arr(int** arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
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
    entryFile(arr, size);
    cout << "sum this arr is = " << func_sum(arr, size) << endl;
    cout << "avg this arr is = " << func_avg(arr, size) << endl;
    cout << "------------Anastasiya Changes--------" << endl;
    cout << "------------START---------------------" << endl;
    findMin(arr, size);
    findMax(arr, size);
    mainDiagonal(arr, size);
    secondaryDiagonal(arr, size);
    cout << "------------END-----------------------" << endl;

    func_del_arr(arr, size);
}

void findMin(int** arr, int len)
{
    int min = INFINITY;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
    }

    cout << "Min number is: " << min << endl;
}

void findMax(int** arr, int len)
{
    int max = -INFINITY;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }

    cout << "Max number is: " << max << endl;
}

void mainDiagonal(int** arr, int len)
{
    int sum = 0;

    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < i + 1; j++)
        {
            sum += arr[i][j];
        }
    }

    cout << "Main diagonal sum is: " << sum << endl;
}

void secondaryDiagonal(int** arr, int len)
{
    int sum = 0;

    for (int i = 0; i < len; i++)
    {
        for (int j = len - i - 1; j < len - i; j++)
        {
            sum += arr[i][j];
        }
    }

    cout << "Secondary diagonal sum is: " << sum << endl;
}
