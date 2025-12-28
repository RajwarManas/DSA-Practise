class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=(n+1)*n/2,arrsum=0;
        for(int i=0;i<nums.size();i++) {  
            arrsum += nums[i] ;
        }
        return sum-arrsum ;
    }
};