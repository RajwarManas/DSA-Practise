class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int MOD = 1e9 + 7;

        vector<vector<pair<int, int>>> graph(n);

        for (auto &road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];

            graph[u].push_back({v, w});
            graph[v].push_back({u, w});
        }

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto [v, w] : graph[u]) {
                long long newDist = d + w;

                if (newDist < dist[v]) {
                    dist[v] = newDist;
                    ways[v] = ways[u];

                    pq.push({newDist, v});
                }
                else if (newDist == dist[v]) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};