/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two one's added together. 
12 is written as XII, which is simply X + II. 
The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. Instead, the number four is written as IV. 
Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX. 
There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.

Example 1:
Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.

Example 2:
Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.

Example 3:
Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/
#include <iostream>

using namespace std;

class Solution {
public:
    static string to_rom(string one, string five, string ten, int num){
        string rom;
        switch (num % 10){
            case 1:
                rom = one;
                break;
            case 2:
                rom = one + one;
                break;
            case 3:
                rom = one + one + one;
                break;
            case 4:
                rom = one + five;
                break;
            case 5:
                rom = five;
                break;
            case 6:
                rom = five + one;
                break;
            case 7:
                rom = five + one + one;
                break;
            case 8:
                rom = five + one + one + one;
                break;
            case 9:
                rom = one + ten;
        }
        return rom;
    }
    static string intToRoman(int num) {
        string roman = "";
        roman = to_rom("I", "V", "X", num % 10);
        num /= 10;
        roman = to_rom("X", "L", "C", num % 10) + roman;
        num /= 10;
        roman = to_rom("C", "D", "M", num % 10) + roman;
        num /= 10;
        roman = to_rom("M", "", "", num % 10) + roman;
        return roman;
    }
};

int main(){
    cout << Solution::intToRoman(3999) << endl;
    cout << Solution::intToRoman(3) << endl;
    cout << Solution::intToRoman(58) << endl;
    cout << Solution::intToRoman(1994) << endl;
    return 0;
}