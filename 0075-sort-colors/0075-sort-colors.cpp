class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int lastZero=-1, lastTwo=n;
        int i=0;
        while(i<lastTwo) {
            if(nums[i]==0) {
                swap(nums[i],nums[++lastZero]);
                i++;
            }
            else if(nums[i]==2) {
                swap(nums[i],nums[--lastTwo]);
            }
            else i++;
        }
    }
};