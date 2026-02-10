class Solution {
public:
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        unordered_map<char,int> need,window;
        for(char x:t) need[x]++;
        string ans;
        int required=need.size(),formed=0,l=0,r=0,minLen=INT_MAX,start=0;
        while(r<s.size()) {
            char c=s[r];
            window[c]++;
            if(need.count(c)&&window[c]==need[c]) formed++;
            while(l<=r&&formed==required) {
                if(r-l+1<minLen) {
                    minLen=r-l+1;
                    start=l;
                }
                char leftChar=s[l];
                window[leftChar]--;
                if(need.count(leftChar)&&window[leftChar]<need[leftChar]) formed--;
                l++;
            }
            r++;
        }
        return minLen==INT_MAX?"":s.substr(start,minLen);
    }
};