class Solution {
public:
    void bfs(int node,vector<vector<int>>& isConnected,vector<int>& vis,queue<int>& q) {
        if(!vis[node]) {
            q.push(node);
            vis[node]=1;
            while(!q.empty()) {
                int front=q.front();
                q.pop();
                for(int i=0;i<isConnected[node].size();i++) {
                    if(isConnected[front][i]==1&&node!=i&&!vis[i]) {
                        q.push(i);
                        vis[i]=1;
                    } 
                }
            }
        }
    } 
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> vis(isConnected.size(),0);
        queue<int> q;
        int count=0;
        for(int i=0;i<isConnected.size();i++) {
            if(!vis[i]) {
                bfs(i,isConnected,vis,q);
                count++;
            }
        }
        return count;
    }
};