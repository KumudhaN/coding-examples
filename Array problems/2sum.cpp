// https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();        
        unordered_map<int,int> dict;
        for(int i=0;i< len;i++){
            int search = target - nums[i];
            //cout << "Searching " << search;
            if (dict.count(search)){                    
                    return {i, dict[search]};
            }
            //cout << "Inserting " << nums[i] << " " << i << endl;
            dict.insert({nums[i], i});
        }
        return {};
    }
};