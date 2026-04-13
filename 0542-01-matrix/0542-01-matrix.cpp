class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        vector<vector<int>> vis (mat.size(),vector<int>(mat[0].size(),0));
        for(int i=0;i<mat.size();i++) {
            for(int j=0;j<mat[0].size();j++) {
                if(mat[i][j]==0) {
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        int dist=0;
        while(!q.empty()) {
            int size=q.size();
            dist++;
            for(int i=0;i<size;i++) {
                pair<int,int> node=q.front();
                int x=node.first;
                int y=node.second;
                q.pop();
                if(x-1>=0&&vis[x-1][y]==0) {
                    vis[x-1][y]=1;
                    mat[x-1][y]=dist;
                    q.push({x-1,y});
                }
                if(y-1>=0&&vis[x][y-1]==0) {
                    vis[x][y-1]=1;
                    mat[x][y-1]=dist;
                    q.push({x,y-1});
                }
                if(x+1<mat.size()&&vis[x+1][y]==0) {
                    vis[x+1][y]=1;
                    mat[x+1][y]=dist;
                    q.push({x+1,y});
                }
                if(y+1<mat[0].size()&&vis[x][y+1]==0) {
                    vis[x][y+1]=1;
                    mat[x][y+1]=dist;
                    q.push({x,y+1});
                }
            }
        }
        return mat;
    }
};