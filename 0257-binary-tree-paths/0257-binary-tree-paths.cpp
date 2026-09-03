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

    void check(TreeNode* root,vector<string> &v,string str){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            str = str + to_string(root->val);
            v.push_back(str);
            return;
        }
        check(root->left,v,str+to_string(root->val)+"->");
        check(root->right,v,str+to_string(root->val)+"->");
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> v;
        check(root,v,"");
        return v;
    }
};