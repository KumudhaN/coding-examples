https://leetcode.com/problems/group-anagrams/description/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len = strs.size();
        std::map<string,vector<string>> dict;
        for(int i=0; i<len;i++){
            string s = strs[i];
            sort(s.begin(), s.end());
                dict[s].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for (auto it : dict){
            result.push_back(it.second);
            
        }
        return result;
    }
};