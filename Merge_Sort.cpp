#include <iostream>
#include <vector>

using namespace std;

// Function to merge two sorted halves
vector<int> merge(const vector<int>& left, const vector<int>& right) {
    vector<int> result;
    size_t i = 0, j = 0;

    // Merge the two sorted halves
    while (i < left.size() && j < right.size()) {
        if (left[i] < right[j]) {
            result.push_back(left[i]);
            i++;
        } else {
            result.push_back(right[j]);
            j++;
        }
    }

    // Append any remaining elements from the left half
    while (i < left.size()) {
        result.push_back(left[i]);
        i++;
    }

    // Append any remaining elements from the right half
    while (j < right.size()) {
        result.push_back(right[j]);
        j++;
    }

    return result;
}

// Function to perform merge sort on the array
vector<int> mergeSort(const vector<int>& arr) {
    if (arr.size() <= 1) {
        return arr;
    }

    size_t mid = arr.size() / 2;
    vector<int> leftHalf(arr.begin(), arr.begin() + mid);
    vector<int> rightHalf(arr.begin() + mid, arr.end());

    vector<int> sortedLeft = mergeSort(leftHalf);
    vector<int> sortedRight = mergeSort(rightHalf);

    return merge(sortedLeft, sortedRight);
}

int main() {
    vector<int> unsortedArr = {3, 7, 6, -10, 15, 23, 55, -13};
    vector<int> sortedArr = mergeSort(unsortedArr);

    cout << "Sorted array: ";
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
