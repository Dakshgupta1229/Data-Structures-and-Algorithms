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

    int max_depth(TreeNode* root,int &max_val){
        if(root==NULL) return 0;
        int left_tree = max(0,max_depth(root->left,max_val));
        int right_tree = max(0,max_depth(root->right,max_val));
        max_val = max(max_val,root->val + left_tree + right_tree);
        return root->val + max(left_tree,right_tree);
    }

    int maxPathSum(TreeNode* root) {
        int max_val = INT_MIN;
        max_depth(root,max_val);
        return max_val;
    }
};