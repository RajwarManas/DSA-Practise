class Solution {
    class Disjoint{
        public:
        vector<int> parent, size;
        Disjoint(int n) {
            parent.resize(n);
            size.resize(n, 1);
            for(int i=0;i<n;i++) {
                parent[i]=i;
            }
        }
        int findP(int x) {
            if (parent[x]==x) return x;
            return parent[x]=findP(parent[x]);
        }
        void unionS(int x,int y) {
            int px = findP(x);
            int py = findP(y);
            if (px==py) return;
            if (size[px]<size[py]) {
                parent[px]=py;
                size[py]+=size[px];
            } else {
                parent[py]=px;
                size[px]+=size[py];
            }
        }
    };
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size()<n-1) return -1;
        Disjoint ds(n);
        for(int i=0;i<connections.size();i++) {
            int u=connections[i][0];
            int v=connections[i][1];
            ds.unionS(u,v);
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            if(ds.findP(i)==i) ans++;
        }
        return ans-1;
    }
};