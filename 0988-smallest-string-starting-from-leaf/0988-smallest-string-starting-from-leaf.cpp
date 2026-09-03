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

    void check(TreeNode* root,string str,vector<string> &v){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            str = str + (char)(root->val+97);
            reverse(str.begin(),str.end());
            v.push_back(str);
            return;
        }
        check(root->left,str+(char)(root->val+97),v);
        check(root->right,str+(char)(root->val+97),v);
    }

    string smallestFromLeaf(TreeNode* root) {
        vector<string> v;
        check(root,"",v);
        sort(v.begin(),v.end());
        return v[0];
    }
};