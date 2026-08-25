#include <vector>
#include <algorithm>

class Solution {
public:
    int maxCount(int m, int n, std::vector<std::vector<int>>& ops) {
        if (ops.empty()) {
            return m * n;
        }

        int min_row = m;
        int min_col = n;

        for (const auto& op : ops) {
            min_row = std::min(min_row, op[0]);
            min_col = std::min(min_col, op[1]);
        }

        return min_row * min_col;
    }
};