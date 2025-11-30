https://leetcode.com/problems/valid-parentheses/
class Solution {
public:
    bool isValid(string s) {
        int head = -1;
        vector<char> stack;
        int len = s.size();
        //cout << "len " << len << std::endl;
        int i=0;
        for(i=0;i<len;i++)
        {
            //cout << "Inside for: Head " << head << " s[i] " << s[i] << std::endl;
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                stack.push_back(s[i]);
                head++;
            }
            else if(s[i] == ')' && head !=-1 && stack[head] == '(')
            {
                stack.pop_back();
                head--;
            }
            else if(s[i] == ']' && head !=-1 && stack[head] == '[')
            {
                stack.pop_back();
                head--;
            }
            else if(s[i] == '}' && head !=-1 && stack[head] == '{')
            {
                stack.pop_back();
                head--;
            }
            else return false;
        }
        if(head == -1){
            return true;
        }
        return false;
    }
};