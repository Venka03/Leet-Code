/*
Given an integer n, 
return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].

Example 1:
Input: n = 3
Output: 3

Example 2:
Input: n = 11
Output: 0
Explanation: The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
*/
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    static int findNthDigit(int n) {
        long int k = n;
        int tmp, i = 1;
        while (k > 0){
            tmp = k;
            k -= i * 9 * pow(10, i-1);
            i++;
        }
        i--; //  the smallest i such that n < 10^i == length of n
        k = tmp;
        tmp = pow(10, i-1);
        tmp += (k-1) / i; // to get number we are working with
        return (tmp / (int) pow(10, i-((k-1) % i)-1)) % 10; // j = (k-1) % i - position from left of wanted digit 
        /*
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
        100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 
        i * 9 * pow(10, i-1) - amount of digits for numbers of length i
        10 - 1
        11 - 0
        2 * 90 number with 2 digit
        190 - 1 // for 100
        191 - 0
        192 - 0
        2890 - 1 // for 1000
        3 * 900
        */
    }
};


int main(){
    cout << "Digit with number 3 is " << Solution::findNthDigit(3) << endl;
    cout << "Digit with number 11 is " << Solution::findNthDigit(11) << endl;
    cout << "Digit with number 121 is " << Solution::findNthDigit(121) << endl;
}