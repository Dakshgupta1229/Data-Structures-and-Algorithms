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

    void traverse(TreeNode* root,string str,vector<string> &v){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            str = str + to_string(root->val);
            v.push_back(str);
            return;
        }
        traverse(root->left,str+to_string(root->val)+"->",v);
        traverse(root->right,str+to_string(root->val)+"->",v);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        traverse(root,"",v);
        return v;
    }
};