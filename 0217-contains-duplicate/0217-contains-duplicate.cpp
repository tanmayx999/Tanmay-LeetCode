#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        for (int num : nums) {
            // std::unordered_set::count or find provides O(1) average lookup
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};