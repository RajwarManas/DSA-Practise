class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> last(3,-1);
        int ans=0;
        for(int i=0;i<s.size();i++) {
            last[s[i]-'a']=i;
            int m=min({last[0],last[1],last[2]});
            if(m!=-1) ans+=m+1;
        }
        return ans;
    }
};