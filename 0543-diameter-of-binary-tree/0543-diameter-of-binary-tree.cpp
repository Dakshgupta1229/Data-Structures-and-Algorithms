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

    void check(TreeNode* root,int &max_val){
        if(root==NULL) return;
        int left_tree = level(root->left);
        int right_tree = level(root->right);
        int sum = left_tree + right_tree;
        if(max_val<sum) max_val = sum;
        check(root->left,max_val);
        check(root->right,max_val);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int max_val = 0;
        check(root,max_val);
        return max_val;
    }
};