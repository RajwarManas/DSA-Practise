class Solution {
public:
    void bfs(vector<vector<char>>& grid,int x,int y,int m,int n) {
        queue<pair<int,int>> q;
        q.push({x,y});
        grid[x][y]='#';
        while(!q.empty()) {
            auto z=q.front();
            q.pop();
            int x=z.first,y=z.second;
            if(x-1>=0&&grid[x-1][y]=='1') {
                q.push({x-1,y});
                grid[x-1][y]='#';
            }
            if(y-1>=0&&grid[x][y-1]=='1') {
                q.push({x,y-1});
                grid[x][y-1]='#';
            }
            if(x+1<m&&grid[x+1][y]=='1') {
                q.push({x+1,y});
                grid[x+1][y]='#';
            }
            if(y+1<n&&grid[x][y+1]=='1') {
                q.push({x,y+1});
                grid[x][y+1]='#';
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]=='1') {
                    bfs(grid,i,j,m,n);
                    count++;
                }

            }
        }
        return count;
    }
};