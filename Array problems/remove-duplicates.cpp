// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        int new_len = 0;
        int len = nums.size();

        for(i=0; i< len-1; i++){
            if(nums[i] == nums[i+1]) continue;
            int new_val = nums[i];
            nums[new_len++] = new_val;
        }
        if(new_len == 0 || nums[new_len-1] != nums[len-1]){
            nums[new_len++] = nums[len-1];
        }
        return new_len;
    }
};