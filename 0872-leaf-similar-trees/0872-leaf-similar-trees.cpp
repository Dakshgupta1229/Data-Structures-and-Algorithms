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

    void traverse(TreeNode* root,vector<int> &v1){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            v1.push_back(root->val);
            return;
        }
        traverse(root->left,v1);
        traverse(root->right,v1);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        vector<int> v2;
        traverse(root1,v1);
        traverse(root2,v2);
        if(v1==v2) return true;
        return false;
    }
};