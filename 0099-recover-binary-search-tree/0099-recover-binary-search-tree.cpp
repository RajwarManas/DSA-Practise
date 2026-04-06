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
    void inorder(TreeNode* root,vector<TreeNode*>& ino) {
        if(!root) return;
        inorder(root->left,ino);
        ino.push_back(root);
        inorder(root->right,ino);
    } 
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> ino;
        TreeNode* first=NULL;
        TreeNode* second=NULL;
        inorder(root,ino);
        for(int i=1;i<ino.size();i++) {
            if(ino[i]->val<ino[i-1]->val) {
                if(!first) first=ino[i-1];
                second=ino[i];
            }
        }
        swap(first->val,second->val);
    }
};