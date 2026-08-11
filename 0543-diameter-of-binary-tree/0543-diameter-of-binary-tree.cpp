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

    void traverse(TreeNode* root,int &max_ele){
        if(root==NULL) return;
        int n = level(root->left) + level(root->right);
        if(max_ele<n) max_ele = n;
        traverse(root->left,max_ele);
        traverse(root->right,max_ele);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int max_ele = 0;
        traverse(root,max_ele);
        return max_ele;
    }
};