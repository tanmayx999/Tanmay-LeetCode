class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int insert_index = 0;
        for(int i=0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[insert_index] = nums[i];
                insert_index++;
            }
        }
        return insert_index;
    }
};