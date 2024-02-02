/*
Given a string s, find the length of the longest substring without repeating characters.

Example 1:
Input: s = "abcabcbb"
Output: 3

Example 2:
Input: s = "bbbbb"
Output: 1

Example 3:
Input: s = "pwwkew"
Output: 3
*/
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
        string sub = "";
        int len = 0, max_len = 0;
        for (int i=0; i<s.size(); i++){
            if (find(sub.begin(), sub.end(), s[i]) != sub.end()) { // check if char is in substring that we check
                if (len > max_len)
                    max_len = len;
                // since we know that char is in substring we can use find to get index and get substring after that index
                sub = sub.substr(sub.find(s[i])+1); 
                len = sub.length();
            }
            sub = sub + s[i];
            len++;
        }
        if (len > max_len)
            max_len = len;
        return max_len;
    }
};

int main(){
    cout << Solution::lengthOfLongestSubstring("dvdf") << endl;
    cout << Solution::lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}