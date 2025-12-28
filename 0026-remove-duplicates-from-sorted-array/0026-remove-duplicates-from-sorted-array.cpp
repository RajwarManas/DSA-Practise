class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0) return 0;
        int lastunique =0;
        for(int i=1;i<nums.size();i++) {
            if(nums[i]!=nums[lastunique]) nums[++lastunique]=nums[i];
        }
        return lastunique+1;
    }
};