class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> colour(n,-1);
        for(int i=0;i<n;i++) {
            if(colour[i]==-1) {
                queue<int> q;
                q.push(i);
                colour[i]=0;
                while(!q.empty()) {
                    int node=q.front();
                    q.pop();
                    for(int nei:graph[node]) {
                        if(colour[nei]==-1) {
                            colour[nei]=1-colour[node];
                            q.push(nei);
                        } else if(colour[nei]==colour[node]) return false;
                    }
                }
            }
        }
        return true;
    }
};