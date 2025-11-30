https://leetcode.com/problems/valid-anagram/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> alpha(26, 0);
        int a_ascii = 97;
        for (int i=0; i < s.length(); i++){
            //cout << " " << s[i] << " " << alpha[s[i]-a_ascii];
            // Storing last known position of the alphabet we are trying to lookup.
            alpha[s[i]-a_ascii] = t.find(s[i], alpha[s[i]-a_ascii]);
            //cout << " " << alpha[s[i]-a_ascii] << endl;
            if (alpha[s[i]-a_ascii] == -1) {
                //cout << s[i] << " ";
                return false;
            }
            alpha[s[i]-a_ascii]++;
        }        
        return true;
    }
};