/*
Given two integers left and right that represent the range [left, right], 
return the bitwise AND of all numbers in this range, inclusive.

Example 1:
Input: left = 5, right = 7
Output: 4

Example 2:
Input: left = 0, right = 0
Output: 0

Example 3:
Input: left = 1, right = 2147483647
Output: 0

*/
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    static int rangeBitwiseAnd(int left, int right) {
        int result = 0, i=0;
        while (i<32 && left|right){
            if (right % 2 && !(left %2)){
                result = 0;
            }
            if (right % 2 && left % 2)
                result += pow(2, i);
            right /= 2;
            left /= 2;
            i++;
        }
        return result;
    }
};
int main(){
    cout << Solution::rangeBitwiseAnd(5, 7) << endl;
    cout << Solution::rangeBitwiseAnd(0, 0) << endl;
    cout << Solution::rangeBitwiseAnd(1, 2147483647) << endl;
}