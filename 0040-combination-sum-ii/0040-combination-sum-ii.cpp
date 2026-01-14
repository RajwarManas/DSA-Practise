class Solution {
public:
    void solve(int pos,vector<int> &candidates,int target,vector<int> &current,vector<vector<int>> &ans) {
        if(target==0) {
            ans.push_back(current);
            return;
        }
        if(pos==candidates.size()||target<0) return;
        current.push_back(candidates[pos]);
        solve(pos+1,candidates,target-candidates[pos],current,ans);
        current.pop_back();
        int nextPos=pos+1;
        while(nextPos<candidates.size()&&candidates[nextPos]==candidates[pos]) {
            nextPos++;
        }
        solve(nextPos,candidates,target,current,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> current;
        vector<vector<int>> ans;
        solve(0,candidates,target,current,ans);
        return ans;
    }
};