class Solution {
    bool cansplit (const vector<int>& nums,int k,int maxsum) {
        int currentsum=0,subarrcount=1;
        for(int i=0;i<nums.size();i++) {
            if (nums[i]>maxsum) return false;
            if (currentsum+nums[i]>maxsum) {
                subarrcount++;
                currentsum=nums[i];
            }
            else currentsum+=nums[i];
        }
        return subarrcount<=k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low=*std::max_element(nums.begin(),nums.end()),
        high=std::accumulate(nums.begin(),nums.end(),0),
        ans=-1;
        while(low<=high) {
            int mid=low+(high-low)/2;
            if(cansplit(nums,k,mid)) {
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
};