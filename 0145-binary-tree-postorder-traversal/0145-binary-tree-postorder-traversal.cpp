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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root==NULL) return v;
        stack<TreeNode*> s;
        s.push(root);
        while(s.size()!=0){
            TreeNode* top = s.top();
            s.pop();
            v.push_back(top->val);
            if(top->left!=NULL) s.push(top->left);
            if(top->right!=NULL) s.push(top->right);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};