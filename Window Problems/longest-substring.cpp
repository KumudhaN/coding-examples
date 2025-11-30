// https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string substring = s.substr(0,1);
        string maxsubstring = s.substr(0,1);
        int len = s.size();
        for(int i=1;i<len;i++){
            if(!substring.contains(s[i])){
                substring.push_back(s[i]);
                if(substring.size() > maxsubstring.size()){
                    maxsubstring = substring;
            }
            }
            else {
            int pos = substring.find(s[i]);
            //std::cout << "len " << substring.size() << " pos " << pos << " substring " << substring << std::endl;
            if(pos !=-1){
                string newsubstr;
                if(pos+1 > substring.size()){
                    //std::cout << "Starting new" << std::endl;
                    newsubstr = "";
                } 
                else {
                    newsubstr = substring.substr(pos+1);
                    //std::cout << "Found smaller " << newsubstr << std::endl;
                }
                
                substring = newsubstr + s[i];
            }
            }
        }
        return maxsubstring.size();
    }
};