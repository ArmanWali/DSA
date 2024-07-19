#include <iostream>
using namespace std;

int main(){
    
int arr[] = {5, -10, 0, -50, 100, 4, 3, 2, -111};
int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++){ 
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        int temp= arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }

    
     for(int j=0; j<sizeof(arr)/sizeof(arr[0]); j++){
        cout<<arr[j]<<" ";
    }  
}