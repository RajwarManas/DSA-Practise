class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int leftMax=0;
        int res=0;
        for(int i=0;i<n;i++) {
            int rightMax=0;
            for(int j=i+1;j<n;j++) {
                rightMax=max(rightMax,height[j]);
            }
            if(height[i]<leftMax&&height[i]<rightMax) res+=min(leftMax,rightMax)-height[i];
            leftMax=max(leftMax,height[i]);
        }
        return res;
    }
};