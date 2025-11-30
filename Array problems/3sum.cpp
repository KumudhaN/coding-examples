//https://leetcode.com/problems/3sum/

//TODO: Need to optimize more

class Solution {
public:

    // vector<pair<int,int>> twoSum(vector<int>& nums, int target, int pos, unordered_map<int,int> dict) {
    //     int len = nums.size();        
    //     //unordered_map<int,int> dict;
    //     vector<pair<int,int>> pairs;
    //     for(int i=pos+1;i< len;i++){
    //         if (i==pos) continue;
    //         int search = target - nums[i];
    //         //cout << "Searching " << search;
    //         if (dict.count(search)){            
    //                 //std::cout << "pos " << pos << " i " << i << " search " << dict[search] << std::endl;
    //                 if(dict[search] > i){       
    //                     pairs.push_back({i, dict[search]});
    //                 }
    //                 i = dict[nums[i]];
    //         }
    //         //cout << "Inserting " << nums[i] << " " << i << endl;
    //         //dict.insert({nums[i], i});
    //     }
    //     if(!pairs.size())
    //         return {};
    //     return pairs;
    // }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int len = nums.size();
        set<vector<int>> triplets;
        unordered_map<int,int> dict;
        sort(nums.begin(), nums.end());
        if(len < 3) return {};
        if(nums[0] > 0) return {};
        for(int i=0; i<len; i++){
            dict[nums[i]] = i;
        }
        for(int i=0;i<len;i++){
            if(nums[i] > 0) break;
            int target = -1* nums[i];
            for(int j=i+1;j< len;j++){
                int search = target - nums[j];
                if (dict.count(search) && dict[search] > j){                
                        vector<int> new_triplet = {nums[i], nums[j], nums[dict[search]]};
                        triplets.insert(new_triplet);
                }
                j = dict[nums[j]];
            }
            //matching_pos = twoSum(nums, -1*nums[i], i, dict);          
            i = dict[nums[i]];
        }
        vector<vector<int>> result(triplets.begin(), triplets.end());
        return result;
    }
};