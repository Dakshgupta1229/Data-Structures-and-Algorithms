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
            str = str + to_string(root->val);
            v.push_back(str);
            return;
        }
        check(root->left,str+to_string(root->val),v);
        check(root->right,str+to_string(root->val),v);
    }

    int sumNumbers(TreeNode* root) {
        vector<string> v;
        check(root,"",v);
        int sum = 0;
        for(int i=0;i<v.size();i++){
            sum = sum + stoi(v[i]);
        }
        return sum;
    }
};