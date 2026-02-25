class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump=0 ;
        for(int i=0;i<nums.size();i++) {
            jump=max(jump,nums[i]);
            if(i==nums.size()-1) {
                return 1 ;
            }
            if(nums[i]==0&&jump==0) {
                return 0;
            }
            jump-- ;
        }
        return 0 ;
    }
};