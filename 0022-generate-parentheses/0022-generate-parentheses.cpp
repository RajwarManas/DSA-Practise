class Solution {
public:
    void solve(int open,int close,int n,string &current,vector<string> &result) {
        if(current.size()==2*n) {
            result.push_back(current);
            return;
        }
        if(open<n) {
            current.push_back('(');
            solve(open+1,close,n,current,result);
            current.pop_back();
        }
        if(close<open) {
            current.push_back(')');
            solve(open,close+1,n,current,result);
            current.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        solve(0,0,n,current,result);
        return result;
    }
};