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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==NULL) return NULL;
        if(original==target) return cloned;
        TreeNode* left_tree = getTargetCopy(original->left,cloned->left,target);
        if(left_tree!=NULL) return left_tree;
        TreeNode* right_tree = getTargetCopy(original->right,cloned->right,target);
        return right_tree;
    }
};