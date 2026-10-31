class Solution {
public:
    int timer=0;
    void dfs(int node,int parent,
            vector<int>& vis,
            vector<int>& tin,
            vector<int>& low,
            vector<vector<int>>& adj,
            vector<vector<int>>& critical) {
        vis[node]=1;
        tin[node]=low[node]=timer++;
        for(int neighbour : adj[node]) {
            if(neighbour==parent) continue;
            if (!vis[neighbour]) {
                dfs(neighbour,node,vis,tin,low,adj,critical);
                low[node]=min(low[node],low[neighbour]);
                if (low[neighbour]>tin[node]) {
                    critical.push_back({node,neighbour});
                }
            }
            else {
                low[node]=min(low[node],tin[neighbour]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto& edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> vis(n,0);
        vector<int> tin(n,-1);
        vector<int> low(n,-1);

        vector<vector<int>> critical;
        for(int i=0;i<n;i++) {
            if (!vis[i]) {
                dfs(i,-1,vis,tin,low,adj,critical);
            }
        }
        return critical;
    }
};