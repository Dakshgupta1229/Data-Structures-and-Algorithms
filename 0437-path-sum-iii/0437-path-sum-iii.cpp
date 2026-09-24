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

    void traverse2(TreeNode* root,int targetSum,long long sum,int &count){
        if(root==NULL) return;
        sum = sum + root->val;
        if(sum==targetSum){
            count++;
        }
        traverse2(root->left,targetSum,sum,count);
        traverse2(root->right,targetSum,sum,count);
    }

    void traverse(TreeNode* root,int targetSum,int &count){
        if(root==NULL) return;
        int sum = 0;
        traverse2(root,targetSum,sum,count);
        traverse(root->left,targetSum,count);
        traverse(root->right,targetSum,count);
    }

    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        traverse(root,targetSum,count);
        return count;
    }
};