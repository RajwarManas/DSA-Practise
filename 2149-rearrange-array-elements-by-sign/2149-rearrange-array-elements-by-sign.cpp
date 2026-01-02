class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n= nums.size(),pos=0,neg=1 ;
        std::vector<int> vec(n);
        for(int i=0;i<n;i++) {
            if(nums[i]>0) {
                vec[pos]=nums[i];
                pos+= 2;
            }else {
                vec[neg]=nums[i];
                neg+= 2;
            }
        }
        return vec;
    }
};