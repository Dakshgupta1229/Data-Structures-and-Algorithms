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

    void traverse(TreeNode* root,string &str){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            str = str + to_string(root->val) + "->";
            return;
        }
        traverse(root->left,str);
        traverse(root->right,str);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string str1 = "";
        string str2 = "";
        traverse(root1,str1);
        traverse(root2,str2);
        cout<<str1<<" "<<str2<<endl;
        if(str1==str2) return true;
        return false;
    }
};