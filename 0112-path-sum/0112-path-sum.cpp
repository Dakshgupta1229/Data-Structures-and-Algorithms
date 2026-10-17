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

    void traverse(TreeNode* root,int target,int sum,bool &flag){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            sum = sum + root->val;
            if(sum==target){
                flag = true;
                return;
            }
        }
        if(flag==true) return;
        traverse(root->left,target,sum+root->val,flag);
        traverse(root->right,target,sum+root->val,flag);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flag = false;
        traverse(root,targetSum,0,flag);
        return flag;
    }
};