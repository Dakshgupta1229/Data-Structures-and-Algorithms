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
    int deepestLeavesSum(TreeNode* root) {
        int result = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            int n = q.size();
            int sum = 0;
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                sum = sum + temp->val;
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            result = sum;
        }
        return result;
    }
};