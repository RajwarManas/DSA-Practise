class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        stack<int> st;
        for(int x:nums) {
            st.push(x);
        }
        for(int i=nums.size()-1;i>=0;i--) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }
            ans.push_back(st.empty()?-1:st.top());
            st.push(nums[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};