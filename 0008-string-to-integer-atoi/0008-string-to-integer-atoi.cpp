class Solution {
public:
    int solve(string s,int i,long long num,int sign) {
        if(i>=s.size()) return num*sign;
        if(s[i]<'0'||s[i]>'9') return num*sign;
        int digit=s[i]-'0';
        num=num*10+digit;
        if(sign==1&&num>=INT_MAX) return INT_MAX;
        if(sign==-1&&-num<=INT_MIN) return INT_MIN;
        return solve(s,i+1,num,sign);
    }
    int myAtoi(string s) {
        int i=0;
        while(i<s.size()&&s[i]==' ') {
            i++;
        }
        int sign=1;
        if(i<s.size()&&s[i]=='+'||s[i]=='-') {
            if(s[i]=='-') sign=-1;
            i++;
        }
        int res=solve(s,i,0,sign);
        return res;
    }
};