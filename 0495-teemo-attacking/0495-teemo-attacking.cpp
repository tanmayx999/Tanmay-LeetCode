#include <vector>
#include <algorithm>

class Solution {
public:
    int findPoisonedDuration(std::vector<int>& timeSeries, int duration) {
        if (timeSeries.empty()) return 0;
        
        int totalTime = 0;
        for (size_t i = 0; i < timeSeries.size() - 1; ++i) {
            totalTime += std::min(duration, timeSeries[i + 1] - timeSeries[i]);
        }
        
        return totalTime + duration;
    }
};