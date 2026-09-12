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

    void traverse(TreeNode* root,int &max_len){
        if(root==NULL) return;
        int sum = level(root->left) + level(root->right);
        if(max_len<sum) max_len = sum;
        traverse(root->left,max_len);
        traverse(root->right,max_len);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int max_len = 0;
        traverse(root,max_len);
        return max_len;
    }
};