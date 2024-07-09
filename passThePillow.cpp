#include <iostream>
using namespace std;

class Solution {
public:
    int passThePillow(int n, int time) {
        int revolution = 2 * (n-1);
        int remaining_time = time % revolution;

        if (remaining_time < n){
            return 1 + remaining_time;
        }
        else{
            return 2*n - (1 + remaining_time);
        }
    }
};

int main(){
    Solution s1;
    int num = 10;
    int time = 13;
    cout<<s1.passThePillow(num, time);
}