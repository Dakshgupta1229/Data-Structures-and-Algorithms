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

    void traverse(TreeNode* root,map<int,int> &m){
        if(root==NULL) return;
        m[root->val]++;
        traverse(root->left,m);
        traverse(root->right,m);
    }

    vector<int> findMode(TreeNode* root) {
        vector<int> v;
        map<int,int> m;
        traverse(root,m);
        int freq = INT_MIN;
        for(auto p:m){
            if(freq<p.second) freq = p.second;
        }
        for(auto p:m){
            if(p.second==freq) v.push_back(p.first);
        }
        return v;
    }
};