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

    void traverse(TreeNode* root,vector<TreeNode*> &v){
        if(root==NULL) return;
        v.push_back(root);
        traverse(root->left,v);
        traverse(root->right,v);
    }

    void flatten(TreeNode* root) {
        if(root==NULL) return;
        vector<TreeNode*> v;
        traverse(root,v);
        for(int i=0;i<v.size()-1;i++){
            TreeNode* temp = v[i];
            TreeNode* temp2 = v[i+1];
            temp->left = NULL;
            temp->right = temp2;
        }
    }
};