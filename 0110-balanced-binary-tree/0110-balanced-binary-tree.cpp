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

    int level(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(level(root->left),level(root->right));
    }

    void traverse(TreeNode* root,bool &flag){
        if(root==NULL) return;
        int left_tree = level(root->left);
        int right_tree = level(root->right);
        if(abs(left_tree-right_tree)>1){
            flag = false;
            return;
        }
        traverse(root->left,flag);
        traverse(root->right,flag);
    }

    bool isBalanced(TreeNode* root) {
        bool flag = true;
        traverse(root,flag);
        return flag;
    }
};