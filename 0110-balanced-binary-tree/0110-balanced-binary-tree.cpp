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

    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int left_tree = height(root->left);
        int right_tree = height(root->right);
        if(abs(left_tree - right_tree)>1) return false;
        bool result1 = isBalanced(root->left);
        if(result1==false) return false;
        bool result2 = isBalanced(root->right);
        return result2;
    }
};