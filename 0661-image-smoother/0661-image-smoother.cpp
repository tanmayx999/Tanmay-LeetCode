#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int sum = 0;
                int count = 0;

                for (int dr = -1; dr <= 1; ++dr) {
                    for (int dc = -1; dc <= 1; ++dc) {
                        int nr = r + dr;
                        int nc = c + dc;

                        if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                            sum += img[nr][nc];
                            count++;
                        }
                    }
                }
                res[r][c] = sum / count;
            }
        }

        return res;
    }
};