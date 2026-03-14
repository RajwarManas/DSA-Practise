class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==0) return 0;
        vector<vector<int>> res;
        for(int i=0;i<n;i++) res.push_back({intervals[i][1],intervals[i][0]});
        sort(res.begin(),res.end());
        int count=0,i=0;
        int endTime=res[i++][0];
        while(i<n) {
            if(res[i][1]<endTime) count++;
            else endTime=res[i][0];
            i++;
        }
        return count;
    }
};