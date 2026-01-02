class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size(), lastpos = 0, lastneg = 1;
        std::vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                ans[lastpos] = nums[i];
                lastpos += 2;
            } else {
                ans[lastneg] = nums[i];
                lastneg += 2;
            }
        }
        return ans;
    }
};