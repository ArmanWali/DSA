#include<iostream>
using namespace std;

void Recursive_binary_Search(int arr[], int left, int right, int target){
    if (left >= right){
        cout<<"Not Found!"<<endl;
        return;
    }

    int mid = (left + right) / 2;

    if (arr[mid] == target){
        cout<<"Index found : "<<mid;
        return;
    }
    else if (arr[mid] > target){
        Recursive_binary_Search(arr, left, (mid-1), target);
    }
    else{
        Recursive_binary_Search(arr, (mid + 1), right, target);
    }
}

int main()
{
    int arr[10] = {1, 10, 11, 12, 40, 44, 60, 69, 78, 79};
    int s = 10;
    
    Recursive_binary_Search(arr, 0, 9, 0);
    return 0;
}