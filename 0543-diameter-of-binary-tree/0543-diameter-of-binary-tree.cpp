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

    void traverse(TreeNode* root,int &max_height){
        if(root==NULL) return;
        int sum =level(root->left) + level(root->right);
        if(max_height<sum) max_height = sum;
        traverse(root->left,max_height);
        traverse(root->right,max_height);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int max_height = INT_MIN;
        traverse(root,max_height);
        return max_height;
    }
};