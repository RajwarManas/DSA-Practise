class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,ans=0,count=0;
        for(int j=0;j<nums.size();j++) {
            if(nums[j]==0) count++;
            while(count>k) {
                if(nums[i]==0) count--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};