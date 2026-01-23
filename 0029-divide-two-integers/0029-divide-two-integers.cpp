class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN&&divisor==-1) return INT_MAX;
        bool sign = (dividend<0)^(divisor<0);
        long long dvd=llabs((long long)dividend);
        long long dvs=llabs((long long)divisor);
        long long ans=0;
        for (int i = 31; i >= 0; i--) {
            if ((dvd >> i) >= dvs) {
                dvd -= (dvs << i);
                ans += (1LL << i);
            }
        }
        return sign?-ans:ans;
    }
};