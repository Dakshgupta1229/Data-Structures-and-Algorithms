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

    int findSecondMinimumValue(TreeNode* root) {
        vector<int> v;
        preorder_traversal(root,v);
        long long min_value = LLONG_MAX;
        for(int i=0;i<v.size();i++){
            if(min_value>v[i]) min_value = v[i];
        }
        long long min_value2 = LLONG_MAX;
        for(int i=0;i<v.size();i++){
            if(v[i]!=min_value && min_value2>v[i]){
                min_value2 = v[i];
            }
        }
        if(min_value2==LLONG_MAX) return -1;
        return min_value2;
    }
};