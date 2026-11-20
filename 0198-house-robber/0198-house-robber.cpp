class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        int first=nums[0];
        int second=max(nums[1],nums[0]);
        for(int i=2;i<n;i++) {
            int temp=max(nums[i]+first,second);
            first=second;
            second=temp;
        }
        return second;
    }
};