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
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->val%2==0){
                if(temp->left!=NULL){
                    if(temp->left->left!=NULL) sum = sum + temp->left->left->val;
                    if(temp->left->right!=NULL) sum = sum + temp->left->right->val;
                }
                if(temp->right!=NULL){
                    if(temp->right->right!=NULL) sum = sum + temp->right->right->val;
                    if(temp->right->left!=NULL) sum = sum + temp->right->left->val;
                }
            }
            if(temp->left!=NULL) q.push(temp->left);
            if(temp->right!=NULL) q.push(temp->right);
        }
        return sum;
    }
};