class Solution {
public:
    int beautycount(int freq[]) {
        int maxfreq = 0, minfreq = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                maxfreq = max(maxfreq, freq[i]);
                minfreq = min(minfreq, freq[i]);
            }
        }
        if (minfreq == INT_MAX)
            return 0;
        return maxfreq - minfreq;
    }
    int beautySum(string s) {
        int n = s.size(), totalcount = 0;
        for (int i = 0; i < n; i++) {
            int freq[26] = {0};
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                totalcount += beautycount(freq);
            }
        }
        return totalcount;
    }
};