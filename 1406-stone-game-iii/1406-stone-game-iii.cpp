#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string stoneGameIII(std::vector<int>& stoneValue) {
        int n = stoneValue.size();
        std::vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            dp[i] = -1e9;
            int current_take = 0;

            for (int k = 1; k <= 3 && i + k <= n; ++k) {
                current_take += stoneValue[i + k - 1];
                dp[i] = std::max(dp[i], current_take - dp[i + k]);
            }
        }

        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};