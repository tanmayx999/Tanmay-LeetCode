#include <vector>
#include <climits>
#include <algorithm>

class Solution {
public:
    int thirdMax(std::vector<int>& nums) {
        long long first = LLONG_MIN;
        long long second = LLONG_MIN;
        long long third = LLONG_MIN;

        for (int n : nums) {
            // Skip duplicates to ensure distinct values
            if (n == first || n == second || n == third) {
                continue;
            }

            if (n > first) {
                third = second;
                second = first;
                first = n;
            } else if (n > second) {
                third = second;
                second = n;
            } else if (n > third) {
                third = n;
            }
        }

        // If a third distinct maximum was found, return it; otherwise return max
        return (third != LLONG_MIN) ? static_cast<int>(third) : static_cast<int>(first);
    }
};