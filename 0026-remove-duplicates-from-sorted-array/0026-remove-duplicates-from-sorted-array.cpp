class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int lastUnique = 0,k=1;
        for(int i=1;i<n;i++) {
            if(nums[i]!=nums[lastUnique]) {
                nums[++lastUnique]=nums[i];
                k++;
            }
        }
        return k;
    }
};