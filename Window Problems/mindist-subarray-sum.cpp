class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        int left_ptr = 0;
        int MAX_DIST = numeric_limits<int>::max();;
        int min_dist = MAX_DIST;
        int cur_sum = nums[0];
        if(cur_sum >= target) min_dist = 0;
        for(int i=1;i<len;i++){
            cur_sum += nums[i];
            while(cur_sum >= target){
                int new_dist = i - left_ptr;
                if(new_dist < min_dist){
                    min_dist = new_dist;
                }
                cur_sum = cur_sum - nums[left_ptr];
                left_ptr++;
            }
        }
        return min_dist == MAX_DIST? 0:min_dist+1;

    }
};