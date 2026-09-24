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
    
    void traverse(TreeNode* root,int targetSum,int sum,vector<int> v1,vector<vector<int>> &v){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            sum = sum + root->val;
            if(sum==targetSum){
                v1.push_back(root->val);
                v.push_back(v1);
            }
            return;
        }
        v1.push_back(root->val);
        traverse(root->left,targetSum,sum+root->val,v1,v);
        traverse(root->right,targetSum,sum+root->val,v1,v);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> v;
        vector<int> v1;
        int sum = 0;
        traverse(root,targetSum,sum,v1,v);
        return v;
    }
};