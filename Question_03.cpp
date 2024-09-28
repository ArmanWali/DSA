#include <iostream>
using namespace std;

void Display_Book_Ids(int *arr, int size);
void Add_new_Book(int *arr, int &size);
void Remove_A_Book(int *arr, int &size);
void Recursive_Linear_Search(int *arr, int size, int index, int target);
void recursive_Bubble_Sort(int *arr, int n, int i = 0);

void Display_Book_Ids(int *arr, int size)
{
    cout << "\nBOOK IDs : ";
    for (int i = 0; i < size; i++)
    {
        cout << *(arr + i) << " ";
    }
}

void Add_new_Book(int *arr, int &size)
{
    string str_ID;
    cout << "\nEnter Your Name (BOOk ID) : ";
    getline(cin, str_ID);
    int Book_ID = 0;

    for (char c : str_ID)
    {
        if (c != ' ')
        {
            Book_ID += (static_cast<int>(c));
        }
    }
    // my birth date is 05/07/2003 so "0+5+0+7+0+3 = 15"
    int index = 15 % size;
    size++;
    for (int i = size; i > index; i--)
    {
        arr[i - 1] = arr[i - 2];
    }
    arr[index] = Book_ID / 2;
}

void Remove_A_Book(int *arr, int &size)
{
    int Book_ID;
    cout << "\nEnter the Book ID you want to remove : ";
    cin >> Book_ID;
    int index;

    for (int i = 0; i < size; i++)
    {
        if (arr[i] == Book_ID)
        {
            index = i;
        }
    }

    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    size--;
}

void Recursive_Linear_Search(int *arr, int size, int index, int target)
{
    if (index == size)
    {
        cout << "\nThe Book ID is not found!." << endl;
    }
    if (arr[index] == target)
    {
        cout << "\nThe Book ID " << target << " is found at index " << index << endl;
        return;
    }

    Recursive_Linear_Search(arr, size, index + 1, target);
}

void recursive_Bubble_Sort(int *arr, int size, int i = 0)
{
    if (size == 1)
    {
        return;
    }

    if (i == size - 1)
    {
        recursive_Bubble_Sort(arr, size - 1, 0);
        return;
    }

    if (arr[i] > arr[i + 1])
    {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }

    recursive_Bubble_Sort(arr, size, i + 1);
}

int main()
{
    int s;
    cout << "Enter the size of array : ";
    cin >> s;
    int *arr = new int[s];
    for (int i = 0; i < s; i++)
    {
        arr[i] = i + 1;
    }

    Display_Book_Ids(arr, s);
    Add_new_Book(arr, s);
    Display_Book_Ids(arr, s);
    Remove_A_Book(arr, s);
    Display_Book_Ids(arr, s);
    Recursive_Linear_Search(arr, s, 0, 2);
    recursive_Bubble_Sort(arr, s);
    Display_Book_Ids(arr, s);

    delete[] arr;
    return 0;
}