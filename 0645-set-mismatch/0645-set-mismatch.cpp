#include <vector>
#include <cmath>
class Solution {
public:
    std::vector<int> findErrorNums(std::vector<int>& nums) {
        int duplicate = -1;
        int missing = -1;

        for (int num : nums) {
            int index = std::abs(num) - 1;
            if (nums[index] < 0) {
                duplicate = std::abs(num);
            } else {
                nums[index] = -nums[index];
            }
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                missing = i + 1;
                break;
            }
        }

        return {duplicate, missing};
    }
};