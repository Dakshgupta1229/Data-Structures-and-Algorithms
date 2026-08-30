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

    void traverse(TreeNode* root,int &val,bool &flag){
        if(root==NULL) return;
        if(root->val!=val){
            flag = false;
            return;
        }
        traverse(root->left,val,flag);
        traverse(root->right,val,flag);
    }

    bool isUnivalTree(TreeNode* root) {
        int val = root->val;
        bool flag = true;
        traverse(root,val,flag);
        return flag;
    }
};