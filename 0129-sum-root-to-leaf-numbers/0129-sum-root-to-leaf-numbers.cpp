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

    void traverse(TreeNode* root,string str,int &sum){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            str = str + to_string(root->val);
            int num = stoi(str);
            sum = sum + num;
            return;
        }
        traverse(root->left,str+to_string(root->val),sum);
        traverse(root->right,str+to_string(root->val),sum);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0;
        traverse(root,"",sum);
        return sum;
    }
};