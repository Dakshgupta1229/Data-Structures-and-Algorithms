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

    int sum(TreeNode* root,int &count){
        if(root==NULL) return 0;
        count++;
        return root->val + sum(root->left,count) + sum(root->right,count);
    }

    void traverse(TreeNode* root,int &count){
        if(root==NULL) return;
        int result = 0;
        int cnt = 0;
        int sum_tree = sum(root,cnt);
        if((sum_tree/cnt)==root->val) count++;
        traverse(root->left,count);
        traverse(root->right,count);
    }

    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        traverse(root,count);
        return count;
    }
};