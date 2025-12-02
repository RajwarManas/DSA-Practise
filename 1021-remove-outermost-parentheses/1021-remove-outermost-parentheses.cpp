class Solution {
public:
    string removeOuterParentheses(string s) {
        std::string ans;
        ans.reserve(s.size());
        int count=0;
        for(int i=0;i<s.size();i++) {
            if(s[i]=='('&&count==0) count++;
            else if(s[i]==')'&&count==1) count--;
            else if(s[i]=='(') {
                count++;
                ans.push_back(s[i]);
            }
            else {
                count--;
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};