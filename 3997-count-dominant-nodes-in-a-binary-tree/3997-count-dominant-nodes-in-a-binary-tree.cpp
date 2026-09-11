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

    void check(TreeNode* root,int &count,int &value){
        if(root==NULL) return;
        if(value<root->val) value = root->val;
        check(root->left,count,value);
        check(root->right,count,value);
    }

    void traverse(TreeNode* root,int &count){
        if(root==NULL) return;
        int value = root->val;
        check(root,count,value);
        if(value==root->val) count++;
        traverse(root->left,count);
        traverse(root->right,count);
    }

    int countDominantNodes(TreeNode* root) {
        int count = 0;
        traverse(root,count);
        return count;
    }
};