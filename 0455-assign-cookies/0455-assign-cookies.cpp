#include <vector>
#include <algorithm>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        
        int child_i = 0;
        int cookie_j = 0;
        
        while (child_i < g.size() && cookie_j < s.size()) {
            if (s[cookie_j] >= g[child_i]) {
                child_i++;
            }
            cookie_j++;
        }
        
        return child_i;
    }
};