class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int n=height.size();
        int water=0;
        for(int i=0;i<n;i++) {
            while(!st.empty()&&height[i]>height[st.top()]) {
                int bottom=st.top();
                st.pop();
                if(st.empty()) break;
                int left=st.top();
                int width=i-left-1;
                int heit=min(height[left],height[i])-height[bottom];
                water+= width*heit;
            }
            st.push(i);
        }
        return water;
    }
};