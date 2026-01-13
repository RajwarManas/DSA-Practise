class Solution {
public:
    long long MOD = 1000000007;
    long long modPow(long long base,long long exp) {
        if(exp==0) return 1;
        long long half=modPow(base,exp/2);
        long long res=(half*half)%MOD;
        if(exp%2==1) res=(res*base)%MOD;
        return res;
    }
    int countGoodNumbers(long long n) {
        long long evenCount=(n+1)/2;
        long long oddCount=n/2;
        long long ans=modPow(5,evenCount);
        ans=(ans*modPow(4,oddCount))%MOD;
        return ans;
    }
};