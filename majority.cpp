
#include <iostream>
#include <vector>
using namespace std;

void partition(int Arr[], int l, int r, int *smallerIndex, int *largerIndex)
{
  int pivot = Arr[l];
  int lastLeft = l;
  int lastRight = r;
  int temp = 0;
  int i = l;
  while (i <= lastRight)
  {
    if (Arr[i] < pivot)
    {
      lastLeft++;
      temp = Arr[i];
      Arr[i] = Arr[lastLeft];
      Arr[lastLeft] = temp;
      i++;
    }
    else if (Arr[i] > pivot)
    {
      temp = Arr[i];
      Arr[i] = Arr[lastRight];
      Arr[lastRight] = temp;
      lastRight--;
    }
    else
    {
      i++;
    }
  }

  Arr[l] = Arr[lastLeft];
  Arr[lastLeft] = pivot;
  *smallerIndex = lastLeft;
  *largerIndex = lastRight;
}
void quickSort(int Arr[], int l, int r)
{

  int smallerIndex;
  int largerIndex;
  if (l >= r)
  {
    return;
  }
  int k = l + rand() % (r - l + 1);
  int temp = Arr[l];
  Arr[l] = Arr[k];
  Arr[k] = temp;
  partition(Arr, l, r, &smallerIndex, &largerIndex);
  quickSort(Arr, l, smallerIndex - 1);
  quickSort(Arr, largerIndex + 1, r);
  
}
int majority(int *arr, int n)
{

  quickSort(arr, 0, n - 1);

  int count = 0;
  bool isMajority = false;
  int currentScanning = arr[0];

  for (int i = 0; i < n; i++)
  {
    if (currentScanning == arr[i])
    {
      count++;
      if (count > n / 2)
      {
        isMajority = true;
        break;
      }
    }
    else
    {
      if (count > n / 2)
      {
        isMajority = true;
        break;
      }
      currentScanning = arr[i];
      count = 1;
    }
  }

  return (isMajority ? currentScanning : 0);
}
int main()
{

  int n;
  cin >> n;
  int *arr = (int *)malloc(n * sizeof(int));

  for (size_t i = 0; i < n; i++)
  {
    std::cin >> arr[i];
  }

  cout << majority(arr, n);
  return 0;
}
