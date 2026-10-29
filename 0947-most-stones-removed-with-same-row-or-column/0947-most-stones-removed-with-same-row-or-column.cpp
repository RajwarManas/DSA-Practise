class Solution {
    class Disjoint {
    public:
        vector<int> parent;
        vector<int> size;

        Disjoint(int n) {
            parent.resize(n);
            size.resize(n, 1);

            for(int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int findP(int x) {
            if(parent[x] == x) return x;
            return parent[x] = findP(parent[x]);
        }

        void unionS(int x, int y) {
            int px = findP(x);
            int py = findP(y);

            if(px == py) return;

            if(size[px] < size[py]) {
                parent[px] = py;
                size[py] += size[px];
            }
            else {
                parent[py] = px;
                size[px] += size[py];
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

        for(auto &stone : stones) {
            ds.unionS(stone[0], stone[1] + offset);
        }

        unordered_set<int> components;

        for(auto &stone : stones) {
            components.insert(ds.findP(stone[0]));
        }

        return stones.size() - components.size();
    }
};