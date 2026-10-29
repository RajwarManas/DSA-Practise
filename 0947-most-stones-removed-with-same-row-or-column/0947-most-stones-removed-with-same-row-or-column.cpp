class Solution {
    class Disjoint{
        public:
        vector<int> parent;
        vector<int>size;
        Disjoint(int n) {
            parent.resize(n);
            size.resize(n,1);
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
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        for(auto &stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }
        int offset = maxRow + 1;
        Disjoint ds(maxRow + maxCol + 2);
        for(auto stone : stones) {
            int r = stone[0];
            int c = stone[1];
            ds.unionS(r,c+offset);
        }
        unordered_set<int> used;
        for(auto &stone : stones) {
            int r = stone[0];
            int c = stone[1] + offset;
            ds.unionS(r, c);
            used.insert(r);
            used.insert(c);
        }
        unordered_set<int> components;
        for(int node : used) {
            components.insert(ds.findP(node));
        }
        return stones.size() - components.size();
    }
};