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
    int widthOfBinaryTree(TreeNode* root) {
        long long max_width = 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(q.size()>0){
            int n = q.size();
            long long val1 = -1;
            long long val2 = -1;
            long long offset = q.front().second;
            for(int i=0;i<n;i++){
                auto it = q.front();
                TreeNode* temp = it.first;
                long long value = it.second;
                value = value - offset;
                q.pop();
                if(val1==-1) val1 = value;
                val2 = value;
                if(temp->left!=NULL) q.push({temp->left,2*value+1});
                if(temp->right!=NULL) q.push({temp->right,2*value+2});
            }
            int sum = val2 - val1 + 1;
            if(max_width<sum) max_width = sum;
        }
        return max_width;

    }
};