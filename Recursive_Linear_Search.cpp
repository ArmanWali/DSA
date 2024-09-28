#include<iostream>
using namespace std;

void Recursive_Linear_Search(int arr[], int size, int i, int target){
    if (i == size){
        cout<<"Not found!";
        return;
    }

    if (arr[i] == target){
        cout<<"Index Found : "<<i<<endl;
        return;
    }
    
    Recursive_Linear_Search(arr, size, i + 1, target);
    
}

int main()
{
    int arr[10] = {1, 10, 11, 12, 40, 44, 60, 69, 78, 79};
    int s = 10;
    Recursive_Linear_Search(arr, s, 0, 44);
    return 0;
}