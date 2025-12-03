https://leetcode.com/problems/find-peak-element/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return 0;
        int mid = len/2;
        while (mid>=0 && mid <len) {
            if(mid == 0){
                if(nums[mid] > nums[mid+1]) return mid;
                else mid = mid+1;
            }
            else if(mid == len-1){
                if(nums[mid] > nums[mid-1]) return mid;
                else mid = mid-1;
            }
            else if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                return mid;
            else if(nums[mid+1] < nums[mid-1]){
                mid = mid-1;
            }
            else{
                mid = mid+1;
            }
        }
        return -1;
    }
};