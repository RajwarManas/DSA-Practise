class Solution {
public:

    void dfs(TreeNode* root,
             unordered_map<TreeNode*,TreeNode*>& mp) {
        if(!root) return;
        
        if(root->left) mp[root->left]=root;
        if(root->right) mp[root->right]=root;
        
        dfs(root->left,mp);
        dfs(root->right,mp);
    }


    void findNodes(TreeNode* node,int k,int dist,vector<int>& res,
                   unordered_map<TreeNode*,TreeNode*>& mp,
                   unordered_map<TreeNode*,bool>& visited) {
        if(!node || visited[node]) return;
        visited[node] = true;
        if(dist == k){
            res.push_back(node->val);
            return;
        }
        findNodes(node->left,k,dist+1,res,mp,visited);
        findNodes(node->right,k,dist+1,res,mp,visited);   
        if(mp.find(node)!=mp.end())
            findNodes(mp[node],k,dist+1,res,mp,visited);
        }
    vector<int> distanceK(TreeNode* root,TreeNode* target,int k) {
        unordered_map<TreeNode*,TreeNode*> mp;
        dfs(root,mp);
        vector<int> res;
        unordered_map<TreeNode*,bool> visited;
        findNodes(target,k,0,res,mp,visited);
        return res;
    }
};