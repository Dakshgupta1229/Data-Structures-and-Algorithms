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

    void check(TreeNode* root,int targetSum,vector<int> v1,vector<vector<int>> &v,int sum){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            sum = sum + root->val;
            v1.push_back(root->val);
            if(sum==targetSum){
                v.push_back(v1);
                return;
            }
        }
        sum = sum + root->val;
        v1.push_back(root->val);
        check(root->left,targetSum,v1,v,sum);
        check(root->right,targetSum,v1,v,sum);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> v;
        vector<int> v1;
        check(root,targetSum,v1,v,0);
        return v;
    }
};