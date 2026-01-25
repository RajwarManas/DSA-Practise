class Solution {
public:
    double solve(double x,int n) {
        if(n==0) return 1.0;
        double ans=solve(x,n/2);
        if(n%2==0) return ans*ans;
        return ans*ans*x;
    }
    double myPow(double x, int n) {
        long long N=n;
        if(N<0) {
            x=1/x;
            N=-N;
        }
        double ans=solve(x,n);
        return ans;
    }
};