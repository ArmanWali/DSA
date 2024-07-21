#include <iostream>
using namespace std;

int main(){
    int arr[] = {10, -15, 0, -50, 100, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=1; i<n; i++){
        int current = arr[i];
        int j = i - 1;

        while(arr[j] > current && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }


    for(int j=0; j<sizeof(arr)/sizeof(arr[0]); j++){
        cout<<arr[j]<<" ";
    }
}