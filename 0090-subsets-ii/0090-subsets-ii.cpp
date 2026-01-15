class Solution {
public:
    void solve(int pos,vector<int> &nums,vector<int> &curr,vector<vector<int>> &ans) {
        ans.push_back(curr);
        int nextPos=pos;
        for (int i = pos; i < nums.size(); i++) {
            if (i > pos && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            solve(i + 1, nums, curr, ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(0,nums,curr,ans);
        return ans;
    }
};