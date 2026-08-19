#include <vector>
#include <algorithm>

class Solution {
public:
    int arrayPairSum(std::vector<int>& nums) {
        // Step 1: Sort the vector in ascending order
        std::sort(nums.begin(), nums.end());
        
        int maxSum = 0;
        // Step 2: Sum every second element starting from index 0
        for (int i = 0; i < nums.size(); i += 2) {
            maxSum += nums[i];
        }
        
        return maxSum;
    }
};