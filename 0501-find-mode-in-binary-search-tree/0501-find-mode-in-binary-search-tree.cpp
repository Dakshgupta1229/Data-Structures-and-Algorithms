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

    void preorder_traversal(TreeNode* root,map<int,int> &m){
        if(root==NULL) return;
        m[root->val]++;
        preorder_traversal(root->left,m);
        preorder_traversal(root->right,m);
    }

    vector<int> findMode(TreeNode* root) {
        map<int,int> m;
        vector<int> v;
        preorder_traversal(root,m);
        int max_freq = 0;
        for(auto p:m){
            if(max_freq<p.second) max_freq = p.second;
        }
        for(auto p:m){
            if(p.second==max_freq){
                v.push_back(p.first);
            }
        }
        return v;
    }
};