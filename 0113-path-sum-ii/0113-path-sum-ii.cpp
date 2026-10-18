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

    void traverse(TreeNode* root,int sum,int target,vector<int> v1,vector<vector<int>> &v){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            sum = sum + root->val;
            v1.push_back(root->val);
            if(sum==target) v.push_back(v1);
            return;
        }
        v1.push_back(root->val);
        traverse(root->left,sum+root->val,target,v1,v);
        traverse(root->right,sum+root->val,target,v1,v);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> v;
        vector<int> v1;
        traverse(root,0,targetSum,v1,v);
        return v;
    }
};