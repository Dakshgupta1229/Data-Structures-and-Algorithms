/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q) return root;
        TreeNode* left_tree = lowestCommonAncestor(root->left,p,q);
        TreeNode* right_tree = lowestCommonAncestor(root->right,p,q);
        if(left_tree==NULL) return right_tree;
        else if(right_tree==NULL) return left_tree;
        else return root;
    }
};