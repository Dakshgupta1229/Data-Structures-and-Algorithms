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

    bool check(TreeNode* root1,TreeNode* root2){
        if(root1==NULL && root2==NULL) return true;
        if(root1!=NULL && root2==NULL) return false;
        if(root1==NULL && root2!=NULL) return false;
        if(root1->val!=root2->val) return false;
        bool flag1 = check(root1->left,root2->right);
        if(flag1==false) return flag1;
        bool flag2 = check(root1->right,root2->left);
        return flag2;
    }

    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        if(root->left==NULL && root->right==NULL) return true;
        bool result = check(root->left,root->right);
        return result;
        
    }
};