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
    unordered_map<int,TreeNode*> mp;
    bool dfs(TreeNode* root,long minVal,long maxVal) {
        if(!root) return true;
        if(root->val<=minVal||root->val>=maxVal) return false;
        if(!root->left&&!root->right&&mp.count(root->val)) {
            TreeNode* node=mp[root->val];
            root->left=node->left;
            root->right=node->right;
            mp.erase(root->val);
        }
        return dfs(root->left,minVal,root->val)&&dfs(root->right,root->val,maxVal);
    }
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_set<int> leaves;
        for(auto t : trees) {
            mp[t->val]=t;
            if(t->left) leaves.insert(t->left->val);
            if(t->right) leaves.insert(t->right->val);
        }
        TreeNode* root=NULL;
            for(auto t : trees) {
                if(!leaves.count(t->val)) {
                    root=t;
                    break;
                }
            }
            if(!root) return NULL;
            mp.erase(root->val);
            if(!dfs(root,LONG_MIN,LONG_MAX)) return NULL;
            if(!mp.empty()) return NULL;
            return root;
    }
};