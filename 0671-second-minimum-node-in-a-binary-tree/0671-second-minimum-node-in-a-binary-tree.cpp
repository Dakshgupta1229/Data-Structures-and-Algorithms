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
        v.push_back(root->val);
        traverse(root->left,v);
        traverse(root->right,v);
    }

    int findSecondMinimumValue(TreeNode* root) {
        vector<int> v;
        traverse(root,v);
        int min_value = v[0];
        long s_value = LLONG_MAX;
        for(int i=1;i<v.size();i++){
            if(min_value>v[i]){
                s_value = min_value;
                min_value = v[i];
            }
            if(s_value>v[i] && v[i]!=min_value){
                s_value = v[i];
            }
        }
        if(s_value==LLONG_MAX) return -1;
        return s_value;
    }
};