#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// A utility function to get the maximum value in an array
int getMax(const vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}

// A function to do counting sort based on the digit represented by exp
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); // output array
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Change count[i] so that count[i] contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr, so that arr now contains sorted numbers according to the current digit
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// The main function to sort an array using Radix Sort
void radixSort(std::vector<int>& arr) {
    // Find the maximum number to know the number of digits
    int m = getMax(arr);

    // Do counting sort for every digit. Note that instead of passing digit number, exp is passed.
    // exp is 10^i where i is the current digit number
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    } 
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 804, 24, 2, 66};
    radixSort(arr);
    
    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
