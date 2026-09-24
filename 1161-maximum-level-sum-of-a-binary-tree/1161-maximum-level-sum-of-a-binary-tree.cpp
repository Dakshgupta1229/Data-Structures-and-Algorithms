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
    int maxLevelSum(TreeNode* root) {
        int idx = -1;
        int count = 1;
        queue<TreeNode*> q;
        q.push(root);
        long long max_val = LLONG_MIN;
        while(q.size()>0){
            int n = q.size();
            long long sum = 0;
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                sum = sum + temp->val;
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            if(max_val<sum){
                max_val = sum;
                idx = count;
            }
            count++;
        }
        return idx;
    }
};