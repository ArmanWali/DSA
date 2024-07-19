#include <iostream>
using namespace std;

int main(){
    int arr[] = {10, -15, 0, -50, 100, 4, 3, 2, 1};
    
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){ 
         for (int j = 0; j < (sizeof(arr)/sizeof(arr[0]))-i-1; j++){     
            if(arr[j] > arr[j+1]){
            int temp=0;
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
        }    
    }

    for(int j=0; j<sizeof(arr)/sizeof(arr[0]); j++){
        cout<<arr[j]<<" ";
    }    
}