#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) {
        int duplicate = -1;
        int missing = -1;

        // Step 1: Mark visited numbers by negating values at index abs(val) - 1
        for (int num : nums) {
            int index = std::abs(num) - 1;
            if (nums[index] < 0) {
                duplicate = std::abs(num); // Already visited
            } else {
                nums[index] = -nums[index];
            }
        }

        // Step 2: Find the unvisited positive entry (its index + 1 is missing)
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                missing = i + 1;
                break;
            }
        }

        return {duplicate, missing};
    }
};