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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        int count = 1;
        while(q.size()>0){
            int n = q.size();
            vector<int> v1;
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                v1.push_back(temp->val);
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            if(count%2==0) reverse(v1.begin(),v1.end());
            count++;
            v.push_back(v1);
        }
        return v;
    }
};