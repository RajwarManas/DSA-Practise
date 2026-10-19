class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==1) return grid[0][0];
        vector<vector<int>> time(n, vector<int>(n, INT_MAX));
        time[0][0]=grid[0][0];
        priority_queue<
        tuple<int,int,int>,
        vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>
        > q;
        q.push({time[0][0],0,0});
        while(!q.empty()) {
            auto [t,i,j] = q.top();
            q.pop();
            int x[]={-1,1,0,0};
            int y[]={0,0,-1,1};
            for(int k=0;k<4;k++) {
                if((i+x[k]<0)||(i+x[k]>=n)||(j+y[k]<0)||(j+y[k]>=n)) continue;
                if(t<time[i+x[k]][j+y[k]]) {
                    int newTime = max(t,grid[i+x[k]][j+y[k]]);
                    if (newTime<time[i+x[k]][j+y[k]]) {
                    time[i+x[k]][j+y[k]]=newTime;
                    q.push({newTime,i+x[k],j+y[k]});
                    }   
                }
            }
        }
        return time[n-1][n-1];
    }
};