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

    void traverse(TreeNode* root1,TreeNode* root2,bool &result){
        if(root1==NULL && root2==NULL) return;
        if(root1==NULL || root2==NULL){
            result = false;
            return;
        }
        if(root1->val!=root2->val){
            result = false;
            return;
        }
        if(result==false) return;
        traverse(root1->left,root2->right,result);
        traverse(root1->right,root2->left,result);
    }

    bool isSymmetric(TreeNode* root) {
        bool result = true;
        traverse(root->left,root->right,result);
        return result;
    }
};