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

    void traverse(TreeNode* root,int value,bool &flag){
        if(root==NULL) return;
        if(root->val!=value){
            flag = false;
            return;
        }
        if(flag==false) return;
        traverse(root->left,value,flag);
        traverse(root->right,value,flag);
    }

    bool isUnivalTree(TreeNode* root) {
        bool flag = true;
        traverse(root,root->val,flag);
        return flag;

    }
};