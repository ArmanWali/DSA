#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 ||  (x % 10 == 0 &&  x != 0)){ //if last digit is 0 -> not palindrome 
            return false;
        }
        
        int half = 0; 
        while ( x > half){    // check through half of the number is enough 
            half = (half * 10) + (x % 10);
            x /= 10;
        }
        if(x == half || x == half / 10){ //when digits are odd then we divide half by 10
            return true;
        }
        
         return false;
    }
};

int main(){
    Solution s1;
    int num = 555;
    cout<<s1.isPalindrome(num);
}