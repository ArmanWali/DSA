#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++){
            for (int j=i+1; j<nums.size(); j++){
                if (nums[i] + nums[j] == target){
                   return {i, j};
                }
            }
            
        }
        return {};
    }
};

int main(){
    Solution s1;
    vector <int> nums = {1, 2, 3, 4, 5};
    int target = 9;
    vector <int> indexes = s1.twoSum(nums, target);
    for(int i : indexes){
        cout<<i<<" ";
    }
}
