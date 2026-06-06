class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        bool rotated = false;
        for(int i=0;i<n-1;i++) {
            if(nums[i]>nums[i+1]) {
                if(!rotated) rotated = true;
                else if(rotated) return false;
            }
        }
        if(rotated&&nums[n-1]>nums[0]) return false;
        return true;
    }
};