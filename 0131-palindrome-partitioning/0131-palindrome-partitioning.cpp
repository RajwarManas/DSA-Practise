class Solution {
public:
    void solve(int pos,string s,vector<string> &curr,vector<vector<string>> &res) {
        if(pos==s.size()) {
            res.push_back(curr);
            return;
        }
        for(int i=pos;i<s.size();i++) {
            if(palindrome(s,pos,i)) {
                curr.push_back(s.substr(pos,i-pos+1));
                solve(i+1,s,curr,res);
                curr.pop_back();
            }
        }
    }
    bool palindrome(string s,int start,int end) {
        while(start<=end) {
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        vector<vector<string>> res;
        solve(0,s,curr,res);
        return res;
    }
};