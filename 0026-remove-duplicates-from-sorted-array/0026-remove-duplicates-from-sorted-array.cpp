class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //check if array is empty
        if(nums.empty()) return 0;
        //initalize index
        int insert_index = 1; //why not 0? - because there is no element before zero index
        //run loop till the size of array
        for(int i = 1; i < nums.size(); i++)
        //condition if current index != previous index then assign that number at insert_index place 
        if(nums[i] != nums[i - 1]){
            nums[insert_index] = nums[i]; //copy it to unique section
            insert_index++; //move writer forward
        }
        //retrun the count of unique elements
        return insert_index;
    }
};