class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int n=s.size(),i=0;
        string ans,word;
        ans.reserve(n);
        while(i<n) {
            while (i<n&&s[i]==' ') i++;
            word.clear();
            while(i<n&&s[i]!=' ') {
                word.push_back(s[i]);
                i++;
            }
            if(!word.empty()) {
                reverse(word.begin(),word.end());
                if(!ans.empty()) ans.push_back(' ');
                ans+=word;
            }
        }
        return ans;
    }
};