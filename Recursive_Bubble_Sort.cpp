#include <iostream>
using namespace std;

void Recursive_Bubble_Sort(int *arr, int size, int i)
{
    if (size == 1)
    {
        return;
    }

    if (i == size - 1)
    {
        Recursive_Bubble_Sort(arr, size - 1, 0);
        return;
    }

    if (arr[i] > arr[i + 1])
    {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }

    Recursive_Bubble_Sort(arr, size, i + 1);
}

int main()
{
    int arr[10] = {1, -10, 11, 120, 0, -44, 60, 169, 278, 79};
    int s = 10;
    Recursive_Bubble_Sort(arr, s, 0);

    for (int i = 0; i < s; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}