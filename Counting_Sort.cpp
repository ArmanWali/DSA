#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

    vector<int> countingSort(const vector<int>& arr) {
    if (arr.empty()) {
        return {};
    }

    int max_val = *max_element(arr.begin(), arr.end());
    vector<int> count(max_val + 1, 0);
    vector<int> output;

    // Count the occurrences of each element in the original array
    for (int num : arr) {
        count[num]++;
    }

    // Append the elements in sorted order to the output array
    for (int i = 0; i < count.size(); i++) {
        while (count[i] > 0) {
            output.push_back(i);
            count[i]--;
        }
    }

    return output;
}

int main() {
    vector<int> unsortedArr = {4, 2, 2, 6, 3, 3, 1, 6, 5, 2, 3};
    vector<int> sortedArr = countingSort(unsortedArr);

    cout << "Sorted array: ";
    for (int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
