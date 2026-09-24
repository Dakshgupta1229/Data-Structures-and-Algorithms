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

    void preorder_traversal(TreeNode* root,vector<int> &v){
        if(root==NULL) return;
        v.push_back(root->val);
        preorder_traversal(root->left,v);
        preorder_traversal(root->right,v);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        preorder_traversal(root,v);
        sort(v.begin(),v.end());
        int max_diff = INT_MAX;
        for(int i=1;i<v.size();i++){
            if(max_diff>v[i]-v[i-1]) max_diff = v[i] - v[i-1];
        }
        return max_diff;
    }
};