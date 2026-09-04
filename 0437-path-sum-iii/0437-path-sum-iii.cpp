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

    void check(TreeNode* root,int targetSum,int &count,long long sum){
        if(root==NULL) return;
        sum = sum + root->val;
        if(sum==targetSum) count++;
        check(root->left,targetSum,count,sum);
        check(root->right,targetSum,count,sum);
    }

    void traverse(TreeNode* root,int targetSum,int &count){
        if(root==NULL) return;
        check(root,targetSum,count,0);
        traverse(root->left,targetSum,count);
        traverse(root->right,targetSum,count);
    }

    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        traverse(root,targetSum,count);
        return count;
    }
};