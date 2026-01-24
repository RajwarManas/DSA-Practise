class Solution {
public:
    void solve(int index,vector<int> nums,vector<int> &current,vector<vector<int>> &result) {
        if(index==nums.size()) {
            result.push_back(current);
            return;
        }
        solve(index+1,nums,current,result);
        current.push_back(nums[index]);
        solve(index+1,nums,current,result);
        current.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        solve(0,nums,current,result);
        return result;
    }
};