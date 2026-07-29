#include <vector>

class NumArray {
private:
    std::vector<int> prefix;

public:
    NumArray(std::vector<int>& nums) {
        // Size prefix vector to n + 1 so prefix[0] = 0
        prefix.resize(nums.size() + 1, 0);
        
        for (int i = 0; i < nums.size(); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        // Range sum [left, right] = prefix[right + 1] - prefix[left]
        return prefix[right + 1] - prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */