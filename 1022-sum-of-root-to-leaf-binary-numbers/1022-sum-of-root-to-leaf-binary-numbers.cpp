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
            int idx = 0;
            for(int i=v.size()-1;i>=0;i--){
                sum = sum + (pow(2,idx) * v[i]);
                idx++;
            }
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