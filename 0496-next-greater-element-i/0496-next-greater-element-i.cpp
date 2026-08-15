#include <vector>
#include <stack>
#include <unordered_map>

class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> next_greater;
        std::stack<int> st;

        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                next_greater[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        std::vector<int> result;
        result.reserve(nums1.size());
        for (int num : nums1) {
            result.push_back(next_greater.count(num) ? next_greater[num] : -1);
        }
        return result;
    }
};