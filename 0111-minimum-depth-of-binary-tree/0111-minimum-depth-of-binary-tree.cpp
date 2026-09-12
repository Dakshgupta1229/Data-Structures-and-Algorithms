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

    void traverse(TreeNode* root,int count,int &min_val){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            count++;
            if(min_val>count) min_val = count;
            return;
        }
        traverse(root->left,count+1,min_val);
        traverse(root->right,count+1,min_val);
    }

    int minDepth(TreeNode* root) {
        int min_val = INT_MAX;
        int count = 0;
        traverse(root,count,min_val);
        if(min_val==INT_MAX) return 0;
        return min_val;
    }
};