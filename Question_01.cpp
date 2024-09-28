#include<iostream>
using namespace std;

void Display_Tasks(int *arr, int size);
void Adding_New_Task(int *arr, int &size);
void Remove_Completed_Task(int *arr, int &size);
void Find_A_Task(int* arr, int size);
void Bubble_Sort(int* arr, int size);

void Display_Tasks(int *arr, int size){
    if (size == 0){
        cout<<"There are no tasks available."<<endl;
    }
    else{
        cout<<"The task IDs are as follow : "<<endl;
        for(int i = 0; i < size; i++){
            cout<<*(arr+i)<<" ";
        }
    }
}

void Adding_New_Task(int *arr, int &size){
    int newTask;
    cout<<"Enter the task you want to insert : ";
    cin>>newTask;
    int temp = newTask;
    size++;
    int sum = 0;
    while(newTask != 0){
        sum += newTask % 10;
        newTask = newTask / 10;
    }

    if (sum > size){
        arr[size-1] = temp;
    }
    else{
        for (int i = size; i > sum; i--){
            arr[i-1] = arr[i-2];
        }
        arr[sum%size] = temp;
    }    
}

void Remove_Completed_Task(int *arr, int &size){
    int ComTask;
    cout<<"Enter the completed task : ";
    cin>>ComTask;
    int index;

    for(int i = 0; i < size; i++){
        if (arr[i] == ComTask){
            index = i;
        }
    }
    
    if (index < size){
        for (int i = index; i < size-1; i ++){
            arr[i] = arr[i+1];
        }
        cout<<"The task "<<ComTask<<" have been successfully deleted."<<endl;
        size--;
    }
    else{
        cout<<"Task Not found in list."<<endl;
    }
}

void Find_A_Task(int* arr, int size){
    int searchTask;
    cout<<"Enter your birthday (ddmmyy) : ";
    cin>>searchTask;

    for(int i = 0; i < size; i++){
        if (arr[i] == searchTask % 1000){
            cout<<"Your Task "<<searchTask % 1000<<" is found at index "<<i<<endl;
            return;
        }
    }
    cout<<"Your task "<<searchTask%1000<<" not found in list."<<endl;
}

void Bubble_Sort(int* arr, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size-i; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main()
{
    int n;
    cout<<"Enter the size of List of Tasks : ";
    cin>>n;
    int* arr = new int[n];

    for(int i = 0; i < n; i++){
        arr[i] = i + 1;
    }

    int choice;
    do {
        cout << "\nTask Manager Menu:\n";
        cout << "1. Add New Task\n";
        cout << "2. Remove Completed Task\n";
        cout << "3. Find a Task\n";
        cout << "4. Sort Tasks\n";
        cout << "5. Display Tasks\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1:
                Adding_New_Task(arr, n);
                break;
            case 2:
                Remove_Completed_Task(arr, n);
                break;
            case 3:
                Find_A_Task(arr, n);
                break;
            case 4:
                Bubble_Sort(arr, n);
                break;
            case 5:
                Display_Tasks(arr, n);
                break;
            case 6:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice! Please enter a number between 1 and 6." << endl;
        }
    } while (choice != 6);

    delete[] arr;
    return 0;
}
