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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> st1,st2;
        if(!root) return {};
        st1.push(root);
        vector<vector<int>> res;
        while(!st1.empty()||!st2.empty()) {
            vector<int> curr1;
            while(!st1.empty()) {
                TreeNode* node=st1.top();
                if(node->left) st2.push(node->left);
                if(node->right) st2.push(node->right);
                curr1.push_back(node->val);
                st1.pop();
            }
            if(!curr1.empty()) res.push_back(curr1);
            vector<int> curr2;
            while(!st2.empty()) {
                TreeNode* node=st2.top();
                if(node->right) st1.push(node->right);
                if(node->left) st1.push(node->left);
                curr2.push_back(node->val);
                st2.pop();
            }
             if(!curr2.empty()) res.push_back(curr2);
        }
        return res;
    }
};