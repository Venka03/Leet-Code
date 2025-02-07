#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    static int minIncrementForUnique(vector<int>& nums) {
        
        return 0;
    }
};


int main(){
    vector<int> nums;
    // vector<int> nums = {3, 2, 1, 2, 1, 7};
    nums.push_back(3);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(7);
    int increments = 0;
    sort(nums.begin(), nums.end());
    for (int i=1; i!=nums.size(); i++){
        if (nums[i] <= nums[i-1]){
            increments += nums[i-1] - nums[i] + 1;
            nums[i] += nums[i-1] - nums[i] + 1;
            
        }
    }
    
    cout << increments << endl;
    return 0;
}