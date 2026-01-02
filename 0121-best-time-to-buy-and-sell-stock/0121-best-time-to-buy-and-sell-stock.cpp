class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit=0,buy=0;
        for(int i=0;i<prices.size();i++) {
            if(prices[i]<prices[buy]) buy=i;
            maxprofit=max(maxprofit,prices[i]-prices[buy]);
        }
        return maxprofit;
    }
};