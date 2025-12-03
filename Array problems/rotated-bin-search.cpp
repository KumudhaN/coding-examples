https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int len = nums.size();
        int r = len - 1;
        if (len == 1){
            if(nums[0] == target) return 0;
            return -1;
        }
        while (l <= r){
            int mid = int((l+r)/2);
            //std::cout << "mid " << mid << std::endl;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target){
                if (nums[mid] > nums[len-1] && nums[0] > target)
                    l = mid + 1;
                else
                    r = mid - 1;
            } 
            else{
                if (nums[mid] < nums[0] && nums[len-1] < target)
                    r = mid - 1;
                else 
                    l = mid + 1;
            }
        }
        return -1;
    }
};