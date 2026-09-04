class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<vector<int>> incoming(graph.size());
        vector<int> outdegree(graph.size(), 0);
        for(int i=0;i<graph.size();i++) {
            for(int j=0;j<graph[i].size();j++) {
                outdegree[i]++;
                incoming[graph[i][j]].push_back(i);
            }
        }
        queue<int> q;
        for(int i=0;i<outdegree.size();i++) {
            if (outdegree[i]==0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()) {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto x : incoming[node]) {
                if (--outdegree[x]==0) q.push(x);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};