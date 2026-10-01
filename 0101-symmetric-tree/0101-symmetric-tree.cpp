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

    void traverse(TreeNode* root1,TreeNode* root2,bool &flag){
        if(root1==NULL && root2==NULL) return;
        if(root1==NULL || root2==NULL){
            flag = false;
            return;
        }
        if(root1->val!=root2->val){
            flag = false;
            return;
        }
        if(flag==false) return;
        traverse(root1->left,root2->right,flag);
        traverse(root1->right,root2->left,flag);
    }

    bool isSymmetric(TreeNode* root) {
        bool flag = true;
        traverse(root->left,root->right,flag);
        return flag;
    }
};