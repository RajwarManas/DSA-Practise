class Solution {
public:
    unordered_map<int,int> cash;
    bool lemonadeChange(vector<int>& bills) {
        for(int x:bills) {
            cash[x]++;
            int change=x-5;
            while(change>0) {
                if(change>=20&&cash[20]>0) {
                    change-=20;
                    cash[20]--;
                }
                else if(change>=10&&cash[10]>0) {
                    change-=10;
                    cash[10]--;
                }
                else if(change>=5&&cash[5]>0) {
                    change-=5;
                    cash[5]--;
                }
                else if(change>0) return false;
            }
        }
        return true;
    }
};