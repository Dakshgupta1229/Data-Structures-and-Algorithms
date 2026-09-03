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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        stack<TreeNode*> s;
        s.push(root);
        vector<int> v;
        while(s.size()>0){
            TreeNode* temp = s.top();
            s.pop();
            v.push_back(temp->val);
            if(temp->right!=NULL) s.push(temp->right);
            if(temp->left!=NULL) s.push(temp->left);
        }
        return v;
    }
};