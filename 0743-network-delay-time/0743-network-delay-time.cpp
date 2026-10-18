class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1, vector<pair<int,int>>());
        for(auto &edge : times) {
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            graph[u].push_back({v, w});
        }
        vector<int> dist(n+1, INT_MAX);
        priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
        > q ;
        dist[k]=0;
        q.push({0, k});
        while(!q.empty()) {
            auto [d, node] = q.top();
            q.pop();
            if (d>dist[node]) continue;
            for(auto [n, wt] : graph[node]) {
                if(d+wt<dist[n]) {
                    dist[n]=d+wt;
                    q.push({d+wt,n});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++) {
            if (dist[i]==INT_MAX) return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};