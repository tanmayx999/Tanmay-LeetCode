#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        // Step 1: Mark visited indices by making values negative
        for (int i = 0; i < nums.size(); ++i) {
            int index = std::abs(nums[i]) - 1;
            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }
        
        // Step 2: Collect all indices that remain positive
        std::vector<int> missing;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                missing.push_back(i + 1);
            }
        }
        
        return missing;
    }
};