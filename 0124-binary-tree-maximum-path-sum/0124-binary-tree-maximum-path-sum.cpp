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
    int pathSum(TreeNode* root,int& maxSum) {
        if(!root) return 0;
        int left=pathSum(root->left,maxSum);
        int right=pathSum(root->right,maxSum);
        if(left>0&&right>0) maxSum=max(maxSum,root->val+left+right);
        else if(left>0) maxSum=max(maxSum,root->val+left); 
        else if(right>0) maxSum=max(maxSum,root->val+right); 
        else {
            maxSum=max(maxSum,root->val);
            return root->val;
        }
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        int maxSum=INT_MIN;
        pathSum(root,maxSum);
        return maxSum;
    }
};