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
        traverse(root->left,v);
        v.push_back(root);
        traverse(root->right,v);
    }

    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL) return root;
        vector<TreeNode*> v;
        traverse(root,v);
        root = v[0];
        for(int i=0;i<v.size()-1;i++){
            TreeNode* temp = v[i];
            TreeNode* temp2 = v[i+1];
            temp2->left = NULL;
            temp2->right = NULL;
            temp->left = NULL;
            temp->right = temp2;
        }
        return root;

    }
};