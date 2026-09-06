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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root->val==x || root->val==y) return false;
        map<int,vector<int>> m;
        queue<TreeNode*> q;
        q.push(root);
        int count = 0;
        while(q.size()>0){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left!=NULL){
                    m[temp->left->val].push_back(temp->val);
                    m[temp->left->val].push_back(count);
                    q.push(temp->left);
                }
                if(temp->right!=NULL){
                    m[temp->right->val].push_back(temp->val);
                    m[temp->right->val].push_back(count);
                    q.push(temp->right);
                }
            }
            count++;
        }
        int parent1 = m[x][0];
        int parent2 = m[y][0];
        int level1 = m[x][1];
        int level2 = m[y][1];
        if(parent1!=parent2 && level1==level2) return true;
        return false;
    }
};