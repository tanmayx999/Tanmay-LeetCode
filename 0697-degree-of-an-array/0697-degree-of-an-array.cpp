#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findShortestSubArray(std::vector<int>& nums) {
        std::unordered_map<int, int> left, right, count;
        int degree = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (left.find(nums[i]) == left.end()) {
                left[nums[i]] = i;
            }
            right[nums[i]] = i;
            count[nums[i]]++;
            degree = std::max(degree, count[nums[i]]);
        }
        
        int min_length = nums.size();
        
        for (auto const& [num, freq] : count) {
            if (freq == degree) {
                min_length = std::min(min_length, right[num] - left[num] + 1);
            }
        }
        
        return min_length;
    }
};