#include <unordered_set>
#include <vector>

class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int>& nums, int k) {
        std::unordered_set<int> seen;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (seen.count(nums[i])) {
                return true;
            }
            seen.insert(nums[i]);
            
            if (seen.size() > k) {
                seen.erase(nums[i - k]);
            }
        }
        return false;
    }
};