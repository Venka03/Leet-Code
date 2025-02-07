"""
Given an integer array nums, return an array answer such that answer[i] 
is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
"""
class Solution:
    @classmethod
    def productExceptSelf(self, nums: list) -> list:
        product = 1
        zeros = 0
        n = len(nums)
        for i in range(n):
            if not nums[i]:
                zeros += 1
            else:
                product *= nums[i]
        answer = [product] * n
        for i in range(n):
            if zeros:
                if zeros > 1 or nums[i]: 
                    answer[i] *= 0
            else:
                answer[i] //= nums[i]
        return answer

print(Solution.productExceptSelf([1, 2, 3, 4]))
print(Solution.productExceptSelf([-1, 1, 0, -3, 3]))
