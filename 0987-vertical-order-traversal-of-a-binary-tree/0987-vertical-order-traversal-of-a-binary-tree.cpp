/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root,int row,int col, map<int,map<int,multiset<int>>> &nodes){
        if(!root) return;
        nodes[col][row].insert(root->val);
        dfs(root->left,row+1,col-1,nodes);
        dfs(root->right,row+1,col+1,nodes);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        dfs(root,0,0,nodes);
        vector<vector<int>> res;
        for(auto &[col,mp]:nodes){
            vector<int> temp;
            for(auto &[row,vals]:mp){
                temp.insert(temp.end(),vals.begin(),vals.end());
            }
            res.push_back(temp);
        }
        return res;
    }
};