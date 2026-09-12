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

    int height(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(height(root->left),height(root->right));
    }

    void traverse(TreeNode* root,bool &flag){
        if(root==NULL) return;
        int diff = abs(height(root->left) - height(root->right));
        if(diff>1){
            flag = false;
            return;
        }
        if(flag==false) return;
        traverse(root->left,flag);
        traverse(root->right,flag);
    }

    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        bool flag = true;
        traverse(root,flag);
        return flag;

    }
};