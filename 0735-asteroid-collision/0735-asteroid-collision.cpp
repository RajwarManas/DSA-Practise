class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n=asteroids.size();
        for(int x:asteroids) {
            bool alive=true;
            while(alive&&!st.empty()&&st.top()>0&&x<0) {
                if(st.top()<-x) st.pop();
                else if(st.top()==-x) {
                    st.pop();
                    alive=false;
                }
                else alive=false;
            }
            if(alive) st.push(x);
        }
        vector<int> res;
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};