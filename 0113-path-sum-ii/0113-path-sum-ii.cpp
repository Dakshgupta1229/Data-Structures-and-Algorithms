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

    void traverse(TreeNode* root,int target,int sum,vector<int> v1,vector<vector<int>> &v){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            v1.push_back(root->val);
            sum = sum + root->val;
            if(sum==target) v.push_back(v1);
            return;
        }
        v1.push_back(root->val);
        traverse(root->left,target,sum+root->val,v1,v);
        traverse(root->right,target,sum+root->val,v1,v);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> v;
        vector<int> v1;
        traverse(root,targetSum,0,v1,v);
        return v;
    }
};