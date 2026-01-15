class Solution {
public:
    void solve(int num,int k,int n,vector<int> &current,vector<vector<int>> &ans) {
        if(n==0&&current.size()==k) {
            ans.push_back(current);
            return;
        }
        if(num>9||n<0||current.size()>k) return;
        current.push_back(num);
        solve(num+1,k,n-num,current,ans);
        current.pop_back();
        solve(num+1,k,n,current,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> current;
        solve(1,k,n,current,ans);
        return ans;
    }
};