class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if (obstacleGrid[m-1][n-1]) return 0;
        vector<vector<int>> grid(m,vector<int>(n,0));
        grid[0][0]=1;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if (obstacleGrid[i][j]==0) {
                    if (i+1<m) grid[i+1][j]+=grid[i][j];
                    if (j+1<n) grid[i][j+1]+=grid[i][j];
                }
            }
        }
        return grid[m-1][n-1];
    }
};