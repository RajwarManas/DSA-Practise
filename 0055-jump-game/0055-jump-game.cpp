class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums[0]==0&&nums.size()>1) return 0;
        int jumps=nums[0];
        for(int i=0;i<nums.size()-1;i++) {
            jumps=max(jumps,nums[i]);
            if(jumps<=0) return false;
            jumps--;
        }
        return true;
    }
};