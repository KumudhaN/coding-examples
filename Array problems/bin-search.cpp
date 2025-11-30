https://leetcode.com/problems/binary-search
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r){
            int mid = int((l+r)/2);
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target and mid > 0)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return -1;
    }
};