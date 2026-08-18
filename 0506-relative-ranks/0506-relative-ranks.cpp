#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score) {
        int n = score.size();
        std::vector<int> indices(n);
        std::iota(indices.begin(), indices.end(), 0);
        
        // Sort indices based on corresponding scores in descending order
        std::sort(indices.begin(), indices.end(), [&score](int a, int b) {
            return score[a] > score[b];
        });
        
        std::vector<std::string> result(n);
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                result[indices[i]] = "Gold Medal";
            } else if (i == 1) {
                result[indices[i]] = "Silver Medal";
            } else if (i == 2) {
                result[indices[i]] = "Bronze Medal";
            } else {
                result[indices[i]] = std::to_string(i + 1);
            }
        }
        
        return result;
    }
};