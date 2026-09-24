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

    void traverse(TreeNode* root,long long min_val,long long max_val,bool &flag){
        if(root==NULL) return;
        if(root->val>=max_val || root->val<=min_val){
            flag = false;
            return;
        }
        if(flag==false) return;
        traverse(root->left,min_val,root->val,flag);
        traverse(root->right,root->val,max_val,flag);
    }

    bool isValidBST(TreeNode* root) {
        bool flag = true;
        traverse(root,LLONG_MIN,LLONG_MAX,flag);
        return flag;
    }
};