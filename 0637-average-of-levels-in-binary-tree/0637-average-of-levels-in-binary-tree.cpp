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
    vector<double> averageOfLevels(TreeNode* root) {
        if(root==NULL) return {};
        vector<double> v;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            int n = q.size();
            double sum = 0;
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                sum = sum + (double)(temp->val);
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            double result = sum/(double)n;
            v.push_back(result);
        }
        return v;
    }
};