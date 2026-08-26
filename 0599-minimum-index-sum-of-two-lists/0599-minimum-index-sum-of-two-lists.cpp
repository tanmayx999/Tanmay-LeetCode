#include <vector>
#include <string>
#include <unordered_map>
#include <climits>

class Solution {
public:
    std::vector<std::string> findRestaurant(std::vector<std::string>& list1, std::vector<std::string>& list2) {
        std::unordered_map<std::string, int> index_map;
        
        // Step 1: Map each string in list1 to its index
        for (int i = 0; i < list1.size(); ++i) {
            index_map[list1[i]] = i;
        }
        
        std::vector<std::string> result;
        int min_sum = INT_MAX;
        
        // Step 2: Traverse list2 and calculate index sums
        for (int j = 0; j < list2.size(); ++j) {
            if (index_map.count(list2[j])) {
                int curr_sum = j + index_map[list2[j]];
                
                if (curr_sum < min_sum) {
                    min_sum = curr_sum;
                    result = {list2[j]}; // Reset with new minimum
                } else if (curr_sum == min_sum) {
                    result.push_back(list2[j]); // Add tie
                }
            }
        }
        
        return result;
    }
};