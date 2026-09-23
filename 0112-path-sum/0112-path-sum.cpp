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

    void traverse(TreeNode* root,int targetSum,int sum,bool &result){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            sum = sum + root->val;
            if(sum==targetSum){
                result = true;
                return;
            }
        }
        if(result==true) return;
        traverse(root->left,targetSum,sum+root->val,result);
        traverse(root->right,targetSum,sum+root->val,result);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        bool result = false;
        int sum = 0;
        traverse(root,targetSum,sum,result);
        return result;
    }
};