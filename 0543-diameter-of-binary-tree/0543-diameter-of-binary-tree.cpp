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
    int maxDepth(TreeNode* root,int& diameter) {
        if(!root) return 0;
        int left=maxDepth(root->left,diameter);
        int right=maxDepth(root->right,diameter);
        diameter=max(diameter,left+right);
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int diameter=0;
        maxDepth(root,diameter);
        return diameter;
    }
};