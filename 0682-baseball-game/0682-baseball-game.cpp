#include <vector>
#include <string>
#include <numeric>

class Solution {
public:
    int calPoints(std::vector<std::string>& operations) {
        std::vector<int> scores;
        
        for (const std::string& op : operations) {
            if (op == "+") {
                scores.push_back(scores.back() + scores[scores.size() - 2]);
            } else if (op == "D") {
                scores.push_back(scores.back() * 2);
            } else if (op == "C") {
                scores.pop_back();
            } else {
                scores.push_back(std::stoi(op));
            }
        }
        
        return std::accumulate(scores.begin(), scores.end(), 0);
    }
};