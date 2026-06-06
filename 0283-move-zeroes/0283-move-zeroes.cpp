class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int lastNonZero = -1;
        int nonZeroCount = 0;
        for(int i=0;i<n;i++) {
            if(nums[i]!=0) {
                nums[++lastNonZero] = nums[i];
                nonZeroCount++;
            }
        }
        int zeroCount = n-nonZeroCount;
        for(int i=n-1;zeroCount>0;zeroCount--) {
            nums[i--]=0;
        }
    }
};