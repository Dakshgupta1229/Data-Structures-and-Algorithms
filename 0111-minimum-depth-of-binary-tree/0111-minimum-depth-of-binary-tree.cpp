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

    void traverse(TreeNode* root,int count,int &min_ele){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            count++;
            if(min_ele>count) min_ele = count;
        }
        traverse(root->left,count+1,min_ele);
        traverse(root->right,count+1,min_ele);
    }

    int minDepth(TreeNode* root) {
        int min_ele = INT_MAX;
        traverse(root,0,min_ele);
        if(min_ele==INT_MAX) return 0;
        return min_ele;
    }
};