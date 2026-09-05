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

    int sm(TreeNode* root){
        if(root==NULL) return 0;
        return root->val + sm(root->left) + sm(root->right);
    }

    void traverse(TreeNode* root,int &sum){
        if(root==NULL) return;
        int left_tree = sm(root->left);
        int right_tree = sm(root->right);
        int result = abs(left_tree-right_tree);
        sum = sum + result;
        traverse(root->left,sum);
        traverse(root->right,sum);
    }

    int findTilt(TreeNode* root) {
        int sum = 0;
        traverse(root,sum);
        return sum;
    }
};