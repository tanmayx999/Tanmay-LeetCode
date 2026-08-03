#include <vector>
#include <algorithm>

class Solution {
private:
    int memo[21][21];

    int solve(int i, int j, const std::vector<int>& nums) {
        // Base case: only one element left
        if (i == j) return nums[i];

        // Return memoized result
        if (memo[i][j] != -1) return memo[i][j];

        // Option 1: Pick left element
        int pickLeft = nums[i] - solve(i + 1, j, nums);

        // Option 2: Pick right element
        int pickRight = nums[j] - solve(i, j - 1, nums);

        return memo[i][j] = std::max(pickLeft, pickRight);
    }

public:
    bool predictTheWinner(std::vector<int>& nums) {
        int n = nums.size();
        
        // Initialize memoization table
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                memo[i][j] = -1;
            }
        }

        // Player 1 wins if max score advantage >= 0
        return solve(0, n - 1, nums) >= 0;
    }
};