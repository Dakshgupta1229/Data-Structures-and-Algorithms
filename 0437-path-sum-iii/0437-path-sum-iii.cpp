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

    void check(TreeNode* root,int target,int &count,long long sum){
        if(root==NULL) return;
        sum = sum + root->val;
        if(sum==target){
            count++;
        }
        check(root->left,target,count,sum);
        check(root->right,target,count,sum);

    }

    void traverse(TreeNode* root,int target,int &count){
        if(root==NULL) return;
        check(root,target,count,0);
        traverse(root->left,target,count);
        traverse(root->right,target,count);
    }

    int pathSum(TreeNode* root, int targetSum) {
        int count = 0;
        traverse(root,targetSum,count);
        return count;
    }
};