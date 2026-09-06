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

    void check(TreeNode* root,TreeNode* subRoot,bool &flag){
        if(root==NULL && subRoot==NULL) return;
        if(root==NULL || subRoot==NULL){
            flag = false;
            return;
        }
        if(root->val!=subRoot->val){
            flag = false;
            return;
        }
        
        if(flag==false) return;
        check(root->left,subRoot->left,flag);
        check(root->right,subRoot->right,flag);
    }

    void traverse(TreeNode* root,TreeNode* subRoot,bool &flag){
        if(root==NULL) return;
        bool flag1 = true;
        check(root,subRoot,flag1);
        if(flag1==true){
            flag = true;
            return;
        }
        if(flag==true) return;
        traverse(root->left,subRoot,flag);
        traverse(root->right,subRoot,flag);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        bool flag = false;
        traverse(root,subRoot,flag);
        return flag;
    }
};