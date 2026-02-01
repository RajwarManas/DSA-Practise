class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        vector<int> left(n),right(n);
        for(int i=0;i<n;i++) {
            while(!st.empty()&&heights[st.top()]>=heights[i]) {
                st.pop();
            }
            left[i]=st.empty()? i+1:i-st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--) {
            while(!st.empty()&&heights[st.top()]>=heights[i]) {
                st.pop();
            }
            right[i]=st.empty()?n-i:st.top()-i;
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            int area=heights[i]*(left[i]+right[i]-1);
            ans=max(ans,area);
        }
        return ans;
    }
};