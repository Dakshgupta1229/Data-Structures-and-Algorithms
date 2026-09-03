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

    void check(TreeNode* root,int value,bool &flag){
        if(root==NULL) return;
        if(root->val!=value){
            flag = false;
            return;
        }
        check(root->left,value,flag);
        check(root->right,value,flag);
    }

    bool isUnivalTree(TreeNode* root) {
        if(root==NULL) return true;
        int value = root->val;
        bool flag = true;
        check(root,value,flag);
        return flag;
    }
};