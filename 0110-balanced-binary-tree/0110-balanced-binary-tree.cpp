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

    int check(TreeNode* root,bool &flag){
        if(root==NULL) return 0;
        if(flag==false) return -1;
        int left_tree = check(root->left,flag);
        int right_tree = check(root->right,flag);
        if(abs(left_tree-right_tree)>1){
            flag = false;
            return -1;
        }
        return 1 + max(check(root->left,flag),check(root->right,flag));

    }

    bool isBalanced(TreeNode* root) {
        bool flag = true;
        check(root,flag);
        return flag;
    }
};