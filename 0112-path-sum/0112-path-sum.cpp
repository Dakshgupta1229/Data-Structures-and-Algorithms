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

    void check(TreeNode* root,int sum,int targetSum,bool &flag){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            sum = sum + root->val;
            if(sum==targetSum){
                flag = true;
                return;
            }
        }
        sum = sum + root->val;
        check(root->left,sum,targetSum,flag);
        check(root->right,sum,targetSum,flag);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flag = false;
        check(root,0,targetSum,flag);
        return flag;
    }
};