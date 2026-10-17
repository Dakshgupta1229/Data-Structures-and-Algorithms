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

    void traverse(TreeNode* root,vector<int> v,int &sum){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            v.push_back(root->val);
            for(int i=1;i<v.size();i++){
                v[i] = (2* v[i-1]) + v[i];
            }
            sum = sum + v[v.size()-1];
            return;
        }
        v.push_back(root->val);
        traverse(root->left,v,sum);
        traverse(root->right,v,sum);
    }

    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        vector<int> v;
        traverse(root,v,sum);
        return sum;
    }
};