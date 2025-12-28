class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lastnonzero=-1,i=0;
        while(i<nums.size()) {
            if (nums[i]!=0) {
                nums[++lastnonzero]=nums[i];
            }
            i++;
        }
        while(lastnonzero+1<nums.size()) {
            nums[++lastnonzero]=0;
        }
    }
};