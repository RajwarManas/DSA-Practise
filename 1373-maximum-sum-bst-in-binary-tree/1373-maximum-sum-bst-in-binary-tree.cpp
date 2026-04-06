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
    int ans=0;
    struct Node{
        bool isBST;
        int sum;
        int minVal;
        int maxVal;
    };
    Node solve(TreeNode* root) {
        if(!root) return {true,0,INT_MAX,INT_MIN};
        Node left=solve(root->left);
        Node right=solve(root->right);
        if(left.isBST&&right.isBST&&root->val>left.maxVal&&root->val<right.minVal) {
            int sum=left.sum+right.sum+root->val;
            ans=max(sum,ans);
            return {true,sum,min(root->val,left.minVal),max(root->val,right.maxVal)};
        }
        return {false,0,0,0};
    }
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};