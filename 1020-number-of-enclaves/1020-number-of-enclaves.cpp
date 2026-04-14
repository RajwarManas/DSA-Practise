class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int totalLand=0,safeLand=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    totalLand++;
                    if(i==0||j==0||i==m-1||j==n-1) {
                        q.push({i,j});
                        grid[i][j]=2;
                        safeLand++;
                    }
                }
            }
        }
        while(!q.empty()) {
            auto node=q.front();
            int x=node.first,y=node.second;
            q.pop();
            if(x-1>=0&&grid[x-1][y]==1) {
                q.push({x-1,y});
                grid[x-1][y]=2;
                safeLand++;
            }
            if(y-1>=0&&grid[x][y-1]==1) {
                q.push({x,y-1});
                grid[x][y-1]=2;
                safeLand++;
            }
            if(x+1<m&&grid[x+1][y]==1) {
                q.push({x+1,y});
                grid[x+1][y]=2;
                safeLand++;
            }
            if(y+1<n&&grid[x][y+1]==1) {
                q.push({x,y+1});
                grid[x][y+1]=2;
                safeLand++;
            }
        }
        return totalLand-safeLand;
    }
};