/*
Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

*/




#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    static bool isPalindrome(int x) {
        string s = to_string(x);
        for (int i=0; i<s.size()/2; i++){
            if (s[i] != s[s.size() - 1 - i]) return false;
        }
        return true;
    }
};

int main(){
    if (Solution::isPalindrome(121)) 
        cout << "Yes, 121 is a palindrome\n";
    else   
        cout << "No, 121 is not a palindrome\n";
    
    if (Solution::isPalindrome(-121)) 
        cout << "Yes, -121 is a palindrome\n";
    else   
        cout << "No, -121 is not a palindrome\n";
    
    if (Solution::isPalindrome(10)) 
        cout << "Yes, 10 is a palindrome\n";
    else   
        cout << "No, 10 is not a palindrome\n";
    
    return 0;
}
