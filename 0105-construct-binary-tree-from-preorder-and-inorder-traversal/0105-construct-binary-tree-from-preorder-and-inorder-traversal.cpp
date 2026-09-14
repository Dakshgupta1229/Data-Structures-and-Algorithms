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

    TreeNode* build(vector<int> &preorder,int pre_start,int pre_end,vector<int> &inorder,int in_start,int in_end,map<int,int> &m){
        if(pre_start>pre_end || in_start>in_end) return NULL;
        TreeNode* root = new TreeNode(preorder[pre_start]);
        int in_value = m[root->val];
        int num = in_value - in_start;
        root->left = build(preorder,pre_start+1,pre_start+num,inorder,in_start,in_value-1,m);
        root->right = build(preorder,pre_start+num+1,pre_end,inorder,in_value+1,in_end,m);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> m;
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]] = i;
        }
        int n = inorder.size();
        TreeNode* root = build(preorder,0,n-1,inorder,0,n-1,m);
        return root;
    }
};