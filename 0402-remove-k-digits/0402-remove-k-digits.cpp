class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        for(int x:num) {
            while(!st.empty()&&st.top()>x&&k>0) {
                st.pop();
                k--;
            }
            st.push(x);
        }
        while(k>0&&!st.empty()) {
            st.pop();
            k--;
        }
        string ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        int i = 0;
        while (i < ans.size() && ans[i] == '0') i++;
        ans=ans.substr(i);
        return ans.empty()?"0":ans;
    }
};