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

    void traverse(TreeNode* root,queue<TreeNode*> &q){
        if(root==NULL) return;
        traverse(root->left,q);
        q.push(root);
        traverse(root->right,q);
    }

    TreeNode* increasingBST(TreeNode* root) {
        queue<TreeNode*> q;
        traverse(root,q);
        TreeNode* temp = q.front();
        temp->left = NULL;
        root = temp;
        q.pop();
        while(q.size()>0){
            TreeNode* t = q.front();
            q.pop();
            t->left = NULL;
            t->right = NULL;
            temp->right = t;
            temp = t;
        }
        return root;
    }
};