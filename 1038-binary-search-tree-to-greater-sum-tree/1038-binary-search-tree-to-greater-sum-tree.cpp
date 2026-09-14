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

    void traverse(TreeNode* root,int &sum){
        if(root==NULL) return;
        sum = sum + root->val;
        traverse(root->left,sum);
        traverse(root->right,sum);
    }

    void traverse2(TreeNode* root,int &sum){
        if(root==NULL) return;
        traverse2(root->left,sum);
        int value = root->val;
        root->val = sum;
        sum = sum - value;
        traverse2(root->right,sum);
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        traverse(root,sum);
        traverse2(root,sum);
        return root;
    }
};