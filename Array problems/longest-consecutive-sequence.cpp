https://leetcode.com/problems/longest-consecutive-sequence/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        sort(nums.begin(), nums.end());
        int max_len = 0;
        int cur_len = 0;
        for(int i=1;i<len;i++){
            //std::cout << " " << nums[i] << " maxlen " << max_len << " curlen " << cur_len << std::endl;
            if(nums[i-1] + 1 == nums[i]){
                cur_len++;
            }
            else if(nums[i-1] == nums[i]){
                continue;
            }
            else {
                if(max_len < cur_len) {
                    max_len = cur_len;
                }
                cur_len = 0;
            }
        }

        // set<int> s(nums.begin(), nums.end());
        // for(auto it=s.begin(); it!=s.end(); it++){
        //     auto next = std::next(it);
        //     if(next!=s.end() && *it + 1 == *next){
        //         cur_len++;
        //     }
        //     else {
        //         if(max_len < cur_len) {
        //             max_len = cur_len;
        //         }
        //         cur_len = 0;
        //     }
        // }
        return max_len < cur_len ? cur_len +1 : max_len+1;
    }
};