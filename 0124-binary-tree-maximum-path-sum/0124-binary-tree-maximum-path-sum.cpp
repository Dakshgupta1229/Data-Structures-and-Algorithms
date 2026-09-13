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

    int max_path(TreeNode* root,int &max_sum){
        if(root==NULL) return 0;
        int left_tree = max(0,max_path(root->left,max_sum));
        int right_tree = max(0,max_path(root->right,max_sum));
        max_sum = max(max_sum,root->val+left_tree+right_tree);
        return root->val + max(left_tree,right_tree);
    }

    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        max_path(root,max_sum);
        return max_sum;
    }
};