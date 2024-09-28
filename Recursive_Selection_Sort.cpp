#include<iostream>
using namespace std;

void Recursive_Selection_Sort(int* arr, int size, int i){
    if (i == size-1){
        return;
    }

    int minIndex = i;
    for (int j = i + 1; j < size; j++){
        if (arr[j] < arr[minIndex]){
            minIndex = j;
        }
    }

    if (minIndex != i){
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }

    Recursive_Selection_Sort(arr, size, (i + 1) );
}

int main()
{
    int arr[10] = {1, -10, 11, 120, 0, -44, 60, 169, 278, 79};
    int s = 10;
    Recursive_Selection_Sort(arr, 10, 0);

    for(int i = 0; i < 10; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}