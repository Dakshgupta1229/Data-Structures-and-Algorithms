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

    void check(TreeNode* root,long long min_ele,long long max_ele,bool &flag){
        if(root==NULL) return;
        if(root->val<=min_ele || root->val>=max_ele){
            flag = false;
            return;
        }
        if(flag==false) return;
        check(root->left,min_ele,root->val,flag);
        check(root->right,root->val,max_ele,flag);
    }

    bool isValidBST(TreeNode* root) {
        bool flag = true;
        check(root,LLONG_MIN,LLONG_MAX,flag);
        return flag;
    }
};