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

    void traverse2(TreeNode* root,int target,long long sum,int &count){
        if(root==NULL) return;
        sum = sum + root->val;
        if(sum==target) count++;
        traverse2(root->left,target,sum,count);
        traverse2(root->right,target,sum,count);
    }

    void traverse(TreeNode* root,int target,int &count){
        if(root==NULL) return;
        traverse2(root,target,0,count);
        traverse(root->left,target,count);
        traverse(root->right,target,count);
    }

    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        traverse(root,targetSum,count);
        return count;
    }
};