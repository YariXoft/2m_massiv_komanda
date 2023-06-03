#include <iostream>
#include <cmath>

using namespace std;

void findMin(int **arr, int len);
void findMax(int **arr, int len);
void mainDiagonal(int **arr, int len);
void secondaryDiagonal(int **arr, int len);

int main()
{
  // findMin(A, len);
  // findMax(A, len);
  // mainDiagonal(A, len);
  // secondaryDiagonal(A, len);

  return 0;
};

void findMin(int **arr, int len)
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

void findMax(int **arr, int len)
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

void mainDiagonal(int **arr, int len)
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

void secondaryDiagonal(int **arr, int len)
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
