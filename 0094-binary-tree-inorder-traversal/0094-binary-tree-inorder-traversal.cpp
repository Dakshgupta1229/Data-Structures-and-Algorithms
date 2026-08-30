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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        while(s.size()>0 || root!=NULL){
            if(root!=NULL){
                s.push(root);
                root = root->left;
            }
            else{
                TreeNode* temp = s.top();
                s.pop();
                v.push_back(temp->val);
                root = temp->right;
            }
        }
        return v;
    }
};