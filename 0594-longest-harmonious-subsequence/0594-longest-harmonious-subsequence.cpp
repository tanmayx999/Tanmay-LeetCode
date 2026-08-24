#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findLHS(std::vector<int>& nums) {
        std::unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int maxLength = 0;
        for (const auto& [key, count] : freq) {
            if (freq.count(key + 1)) {
                maxLength = std::max(maxLength, count + freq.at(key + 1));
            }
        }

        return maxLength;
    }
};