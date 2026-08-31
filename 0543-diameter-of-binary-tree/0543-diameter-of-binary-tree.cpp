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

    void traverse(TreeNode* root,int &max_depth){
        if(root==NULL) return;
        int left_tree = level(root->left);
        int right_tree = level(root->right);
        if(max_depth<(left_tree+right_tree)) max_depth = left_tree + right_tree;
        traverse(root->left,max_depth);
        traverse(root->right,max_depth);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int max_depth = 0;
        traverse(root,max_depth);
        return max_depth;
    }
};