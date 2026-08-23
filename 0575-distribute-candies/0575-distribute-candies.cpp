#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int distributeCandies(std::vector<int>& candyType) {
        // The maximum number of candies Alice is allowed to eat
        int max_allowed = candyType.size() / 2;
        
        // Count unique candy types by inserting into an unordered_set
        std::unordered_set<int> unique_candies(candyType.begin(), candyType.end());
        
        // Return the minimum of unique types and maximum allowed candies
        return std::min((int)unique_candies.size(), max_allowed);
    }
};