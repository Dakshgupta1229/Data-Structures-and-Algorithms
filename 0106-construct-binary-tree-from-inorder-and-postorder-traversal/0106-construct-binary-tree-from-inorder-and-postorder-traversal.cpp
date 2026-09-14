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

    TreeNode* build(vector<int> &inorder,int in_start,int in_end,vector<int> &postorder,int post_start,int post_end,map<int,int> &m){
        if(in_start>in_end || post_start>post_end) return NULL;
        TreeNode* root = new TreeNode(postorder[post_end]);
        int in_value = m[root->val];
        int num = in_value - in_start;
        root->left = build(inorder,in_start,in_value-1,postorder,post_start,post_start+num-1,m);
        root->right = build(inorder,in_value+1,in_end,postorder,post_start+num,post_end-1,m);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> m;
        for(int i=0;i<inorder.size();i++) m[inorder[i]] = i;
        int n = inorder.size();
        TreeNode* root = build(inorder,0,n-1,postorder,0,n-1,m);
        return root;
    }
};