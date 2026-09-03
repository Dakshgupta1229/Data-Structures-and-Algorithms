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

    void check(TreeNode* root,string &str){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            str = str + to_string(root->val) + "->";
        }
        check(root->left,str);
        check(root->right,str);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string str1,str2;
        check(root1,str1);
        check(root2,str2);
        if(str1==str2) return true;
        return false;
    }
};