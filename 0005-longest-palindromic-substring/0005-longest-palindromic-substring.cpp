class Solution {
public:
    void expand(string &s,int left,int right,int &bestlen,int &start) {
        while(left>=0&&right<s.size()&&s[left]==s[right]) {
            left--;
            right++;
        }
        if(right-left-1>bestlen) {
            start=left+1;
            bestlen=right-left-1;
        }
    }
    string longestPalindrome(string s) {
        int n=s.size();
        if (n==0) return "" ;
        int start=0,bestlen=1;
        for(int i=0;i<n;i++) {
            expand(s,i,i,bestlen,start);
            expand(s,i,i+1,bestlen,start);
        }
        return s.substr(start,bestlen);
    }
};