class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> um ;
        for(int i=0;i<nums.size();i++) {
            int need = target-nums[i];
            if(um.find(need)!=um.end()) {
                return {i,um[need]};
            }
            um[nums[i]]=i;
        }
        return {0};
    }
};