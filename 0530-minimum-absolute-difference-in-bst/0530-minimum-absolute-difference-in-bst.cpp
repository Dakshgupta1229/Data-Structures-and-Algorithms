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

    void traverse(TreeNode* root,vector<int> &v){
        if(root==NULL) return;
        traverse(root->left,v);
        v.push_back(root->val);
        traverse(root->right,v);
    }

    int getMinimumDifference(TreeNode* root) {
        if(root==NULL) return 0;
        vector<int> v;
        traverse(root,v);
        int diff = INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            if(diff>(v[i+1]-v[i])) diff = v[i+1] - v[i];
        }
        return diff;
    }
};