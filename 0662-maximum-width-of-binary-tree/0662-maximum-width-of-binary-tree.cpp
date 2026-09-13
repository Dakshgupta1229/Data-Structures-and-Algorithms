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
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        int max_width = 0;
        while(q.size()>0){
            int min_value = 0;
            int max_value = 0;
            int n = q.size();
            for(int i=0;i<n;i++){
                auto it = q.front();
                q.pop();
                TreeNode* temp = it.first;
                long long index = it.second;
                if(i==0) min_value = index;
                if(i==n-1) max_value = index;
                index = index - min_value;
                if(temp->left!=NULL) q.push({temp->left,2*index+1});
                if(temp->right!=NULL) q.push({temp->right,2*index+2});
            }
            if(max_width<(max_value-min_value+1)) max_width = max_value - min_value + 1;
        }
        return max_width;
    }
};