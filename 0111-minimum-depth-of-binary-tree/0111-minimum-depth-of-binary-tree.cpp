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

    void traverse(TreeNode* root,int count,int &min_height){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            count++;
            if(min_height>count) min_height = count;
            return;
        }
        traverse(root->left,count+1,min_height);
        traverse(root->right,count+1,min_height);
    }

    int minDepth(TreeNode* root) {
        int min_height = INT_MAX;
        int count = 0;
        traverse(root,count,min_height);
        if(min_height==INT_MAX) return 0;
        return min_height;
    }
};