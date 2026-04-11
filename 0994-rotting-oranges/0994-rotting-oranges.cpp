class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        queue<pair<int,int>> q;
        int freshCount=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) freshCount++;
                else if(grid[i][j]==2) q.push({i,j});
            }
        }
        int ans=0;
        while(!q.empty()&&freshCount>0) {
            int size=q.size();
            for(int i=0;i<size;i++) {
                pair<int,int> node=q.front();
                q.pop();
                int x=node.first,y=node.second;
                if(x-1>=0&&grid[x-1][y]==1) {
                    grid[x-1][y]=2;
                    q.push({x-1,y});
                    freshCount--;
                }
                if(y-1>=0&&grid[x][y-1]==1) {
                    grid[x][y-1]=2;
                    q.push({x,y-1});
                    freshCount--;
                }
                if(x+1<m&&grid[x+1][y]==1) {
                    grid[x+1][y]=2;
                    q.push({x+1,y});
                    freshCount--;
                }
                if(y+1<n&&grid[x][y+1]==1) {
                    grid[x][y+1]=2;
                    q.push({x,y+1});
                    freshCount--;
                }
            }
            ans++;
        }
        return freshCount<=0?ans:-1;
    }
};