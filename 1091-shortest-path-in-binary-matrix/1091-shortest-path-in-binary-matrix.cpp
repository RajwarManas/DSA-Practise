class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid[0][0]==1) return -1;
        if (grid.size()==1&&grid[0][0]==0) return 1;
        vector<vector<bool>> vis;
        vector<bool> row(grid.size(), 0);
        for(int i=0;i<grid.size();i++) {
            vis.push_back(row);
        }
        queue<pair<int,int>> q;
        int counter=1;
        q.push({0, 0});
        vis[0][0]=1;
        while(!q.empty()) {
            int size=q.size();
            for(int i=0;i<size;i++) {
                auto [x, y] = q.front();
                q.pop();
                if (x==grid.size()-1&&y==grid[0].size()-1) return counter;
                for(int j=-1;j<2;j++) {
                    for(int k=-1;k<2;k++) {
                        if (j==0&&k==0) continue;
                        if (x+j<0||x+j>=grid.size()||y+k<0||y+k>=grid.size()) continue;
                        if (grid[x+j][y+k]==0&&vis[x+j][y+k]==0) {
                            q.push({x+j,y+k});
                            vis[x+j][y+k]=1;
                        }
                    }
                }
            } 
            counter++;
        }
        return -1;
    }
};