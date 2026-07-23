#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int single = 0;
        for (int num : nums) {
            single ^= num; // Bitwise XOR
        }
        return single;
    }
};