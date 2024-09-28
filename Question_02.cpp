#include<iostream>
using namespace std;

void Display_Events(int* arr , int size);
void Insertion(int* arr, int &size);
void cancelAnEvent(int *arr, int &size);
void Selection_Sort(int* arr, int size);
void Binary_Search(int* arr, int size);

void Display_Events(int* arr , int size){
    
    if (size == 0){
        cout<<"There is no event."<<endl;
    }
    else{
        cout<<"The events are : ";
        for(int i = 0; i < size; i++){
            cout<<*(arr+i)<<" ";
        }
    }
}

void Insertion(int* arr, int &size){
    int newEvent;
    cout<<"\nEnter the new Event you want to insert : ";
    cin>>newEvent;
    int assciValue = 0;
    newEvent = newEvent/10000;
    while(newEvent != 0){
      assciValue += static_cast<int>( (newEvent % 10)+ '0');
        newEvent /= 10;
    }
    int BirthYear;
    cout<<"\nPlease Enter your Birth Year : ";
    cin>>BirthYear;
    int Index = 0;

    for(int i = 0; i < 2; i++){
        Index += BirthYear % 10;
        BirthYear /= 10;
    }
    size++;
    for(int i = size; i > Index; i--){
        arr[i-1] = arr[i-2];
    }
    arr[Index] = assciValue;
}

void cancelAnEvent(int *arr, int &size){
    int canEvent;
    cout<<"\nEnter the event you want to cancel : ";
    cin>>canEvent;
    int index;


    for(int i = 0; i < size; i++){
        if (arr[i] == canEvent){
            index = i;
        }
    }
    
    if (index < size){
        for (int i = index; i < size-1; i ++){
            arr[i] = arr[i+1];
        }
        cout<<"\nThe task "<<canEvent<<" have been successfully deleted."<<endl;
        size--;
    }
    else{
        cout<<"\nTask Not found in list."<<endl;
    }
}

void Selection_Sort(int* arr, int size){
    for (int i = 0; i < size; i++){
        int minIndex = i;
        for (int j = i + 1; j < size; j++ ){
            if (arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void Binary_Search(int* arr, int size){
    int target;
    cout<<"\nEnter the event ID you want to search : ";
    cin>>target;

    int first = 0; 
    int last = size-1;

    while (first <= last){
        int mid = (first + last) / 2;
        if (arr[mid] == target){
            cout<<"\nThe event "<<target<<" is found at Index : "<<mid<<endl;
            return;
        }
        else if(arr[mid] > target){
            last = mid - 1;
        }
        else{
            first = mid + 1;
        }
    }
}

int main()
{   
    int s;
    cout<<"Enter the size of List of Events : ";
    cin>>s;
    int* arr = new int[s];

    for(int i = 0; i < s; i++){
        arr[i] = i + 1;
    }
    Display_Events(arr, s);
    Insertion(arr, s);
    Display_Events(arr, s);
    cancelAnEvent(arr, s);
    Display_Events(arr, s);
    Selection_Sort(arr, s);
    cout<<"\nThe list of events after sorting is : ";
    Display_Events(arr, s);
    Binary_Search(arr, s);
    delete[] arr;
    return 0;
}