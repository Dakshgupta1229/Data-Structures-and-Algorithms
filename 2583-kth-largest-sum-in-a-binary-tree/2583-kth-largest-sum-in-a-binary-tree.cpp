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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);
        vector<long long> v;
        while(q.size()>0){
            int n = q.size();
            long long sum = 0;
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                sum = sum + (long long)(temp->val);
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            v.push_back(sum);
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        if(k-1<v.size()) return v[k-1];
        return -1;
    }
};