#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0;
        for (int num : arr) {
            if (num % 2 != 0) {
                count++;
                if (count == 3) {
                    return true;
                }
            } else {
                count = 0;
            }
        }
        return false;
    
    }
};

int main(){
    Solution s1;
    vector <int> arr = {1, 3, 4, 5, 7, 9, 10};
    cout<<s1.threeConsecutiveOdds(arr);
}