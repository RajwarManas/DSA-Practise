class Solution {
    class Disjoint {
    public:
        vector<int> parent, size;
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
            if(size[py] < size[px]) {
                parent[py] = px;
                size[px] += size[py];
            } else {
                parent[px] = py;
                size[py] += size[px];
            }
        }
    };
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        Disjoint ds(n);
        unordered_map<string, int> um;
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if(um.find(email) == um.end()) {
                    um[email] = i;
                } else {
                    ds.unionS(um[email], i);
                }
            }
        }
        vector<vector<string>> merged(n);
        for(auto& [email, index] : um) {
            int parent = ds.findP(index);
            merged[parent].push_back(email);
        }
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++) {
            if(merged[i].empty()) continue;
            sort(merged[i].begin(), merged[i].end());
            merged[i].insert(
                merged[i].begin(),
                accounts[i][0]
            );
            ans.push_back(merged[i]);
        }
        return ans;
    }
};