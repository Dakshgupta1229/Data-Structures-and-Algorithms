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

    void traverse(TreeNode* root,int count,int &min_depth){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            count++;
            if(min_depth>count) min_depth = count;
            return;
        }
        traverse(root->left,count+1,min_depth);
        traverse(root->right,count+1,min_depth);
    }

    int minDepth(TreeNode* root) {
        int min_depth = INT_MAX;
        traverse(root,0,min_depth);
        if(min_depth==INT_MAX) return 0;
        return min_depth;
    }
};