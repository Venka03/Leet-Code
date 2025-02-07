'''
Given a positive integer n, find the pivot integer x such that:
The sum of all elements between 1 and x inclusively equals 
the sum of all elements between x and n inclusively.
Return the pivot integer x. If no such integer exists, return -1.
It is guaranteed that there will be at most one pivot index for the given input.

 

Example 1:
Input: n = 8
Output: 6
Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.

Example 2:
Input: n = 1
Output: 1
Explanation: 1 is the pivot integer since: 1 = 1.

Example 3:
Input: n = 4
Output: -1
Explanation: It can be proved that no such integer exist.
'''
class Solution:
    @classmethod
    def pivotInteger(self, n: int) -> int:
        sum1 = 0
        sum2 = n
        i = 0
        j = 0
        while i<=n-j:
            if sum2>sum1:
                i+=1
                sum1 += i
            elif sum1>sum2:
                j+=1
                sum2 += n-j
            else:
                if i + j == n:
                    return i
                i += 1
                sum1 += i
        return -1


print(Solution.pivotInteger(8))
print(Solution.pivotInteger(1))
print(Solution.pivotInteger(4))
print(Solution.pivotInteger(49))