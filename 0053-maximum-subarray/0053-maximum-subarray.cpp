class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,maxsum=INT_MIN;
        for(int i=0;i<nums.size();i++) {
            sum+=nums[i];
            if(sum<0) sum=0;
            maxsum=max(maxsum,sum);
        }
        return maxsum;
    }
};