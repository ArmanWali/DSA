#include <iostream>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j=low; j<high; j++){
        if(arr[j] <= pivot){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    i++;
    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;
    return i;
}

void QuickSort(int arr[], int low, int high){
    if(low < high){
        int pivot_index = partition(arr, low, high);

        QuickSort(arr, low, pivot_index-1);
        QuickSort(arr, pivot_index+1, high);
    }
}

int main(){
    int arr[] = {10, -15, 0, -50, 100, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    QuickSort( arr, 0, n-1);

    for(int k=0; k<n; k++){
        cout<<arr[k]<<" ";
    }
}