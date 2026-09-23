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

    void traverse(TreeNode* root,int val,bool &result){
        if(root==NULL) return;
        if(root->val!=val){
            result = false;
            return;
        }
        if(result==false) return;
        traverse(root->left,val,result);
        traverse(root->right,val,result);
    }

    bool isUnivalTree(TreeNode* root) {
        bool result = true;
        traverse(root,root->val,result);
        return result;
    }
};