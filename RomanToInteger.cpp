#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        
        int sum = 0;
        for (size_t i = 0; i < s.length() - 1; ++i) {
            if (roman[s[i]] < roman[s[i + 1]]) {
                sum -= roman[s[i]];
            } else {
                sum += roman[s[i]];
            }
        }
        sum += roman[s.back()]; // Add the last character value
        return sum;
    }
};

int main(){
    Solution s1;
    string str = "XCIX";
    cout<<s1.romanToInt(str);
}