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

    void traverse(TreeNode* root,int k,int &count,int &value){
        if(root==NULL) return;
        traverse(root->left,k,count,value);
        if(count==k){
            value = root->val;
            count++;
            return;
        }
        count++;
        traverse(root->right,k,count,value);
    }

    int kthSmallest(TreeNode* root, int k) {
        int value = INT_MIN;
        int count = 1;
        traverse(root,k,count,value);
        return value;
    }
};