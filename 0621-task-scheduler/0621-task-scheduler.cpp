class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        int maxFreq=0,maxCount=0;
        for(char x:tasks) {
            freq[x-'A']++;
            maxFreq=max(maxFreq,freq[x-'A']);
        }
        for(int x:freq) {
            if(x==maxFreq) maxCount++;
        }
        int minTime=(maxFreq-1)*(n+1)+maxCount;
        return max(minTime,(int)tasks.size());
    }
};