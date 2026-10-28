class Solution {
    class Disjoint {
        public:
        vector<vector<pair<int,int>>> parent;
        vector<vector<int>> size;
        Disjoint(int n) {
            parent.resize(n);
            for(int i=0;i<n;i++) {
                parent[i].resize(n);
                for(int j=0;j<n;j++) {
                    parent[i][j]={i,j};
                }
            }
            size.resize(n,vector<int>(n,1));
        }
        pair<int,int> findP(pair<int,int> p) {
            auto [x,y] = p;
            if (parent[x][y]==p) return p;
            return parent[x][y]=findP(parent[x][y]);
        }
        void unionS(pair<int,int> p1,pair<int,int> p2) {
            auto px=findP(p1);
            auto py=findP(p2);
            auto [m,n]=px;
            auto [o,p]=py;
            if (px==py) return;
            if (size[m][n]<size[o][p]) {
                parent[m][n]=py;
                size[o][p]+=size[m][n];
            } else {
                parent[o][p]=px;
                size[m][n]+=size[o][p];
            }
        }
    };
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        Disjoint ds(n);
        int x[]={0,0,-1,1};
        int y[]={-1,1,0,0};
        bool allOnes=true;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==0) {
                    allOnes=false;
                    continue;
                }
                for(int k=0;k<4;k++) {
                    if(i+x[k]<0||i+x[k]>=n||j+y[k]<0||j+y[k]>=n) continue;
                    int ni=i+x[k],nj=j+y[k];
                    if(grid[ni][nj]==1) {
                        ds.unionS({i,j},{ni,nj});
                    }
                }
            }
        }
        if (allOnes) return n*n;
        int ans=0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) continue;
                int maxSize=1;
                set<pair<int,int>> is;
                for(int k=0;k<4;k++) {
                    if(i+x[k]<0||i+x[k]>=n||j+y[k]<0||j+y[k]>=n) continue;
                    int ni=i+x[k],nj=j+y[k];
                    if(grid[ni][nj]==1) {
                        auto p = ds.findP({ni,nj});
                        if (is.insert(p).second) {
                            auto [a,b]=p;
                            maxSize+=ds.size[a][b];
                        }
                    }
                }
                ans=max(ans,maxSize);
            }
        }
        return ans;
    }
};