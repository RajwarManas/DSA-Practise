class Solution {
public:
    void solve(int pos,vector<int> &candidates,int target,vector<int> &current,vector<vector<int>> &result) {
        if(target==0) {
            result.push_back(current);
            return ;
        }
        if(pos==candidates.size()||target<0) return ;
        current.push_back(candidates[pos]);
        solve(pos,candidates,target-candidates[pos],current,result);
        current.pop_back();
        solve(pos+1,candidates,target,current,result);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        solve(0,candidates,target,current,result);
        return result;
    }
};