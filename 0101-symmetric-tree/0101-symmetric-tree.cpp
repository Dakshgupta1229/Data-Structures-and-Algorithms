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

    bool check(TreeNode* root1,TreeNode* root2,bool &flag){
        if(root1==NULL && root2==NULL) return true;
        if(root1==NULL || root2==NULL){
            flag = false;
            return false;
        }
        if(root1->val!=root2->val){
            flag = false;
            return false;
        }
        bool result1 = check(root1->left,root2->right,flag);
        if(result1==false){
            flag = false;
            return false;
        }
        bool result2 = check(root1->right,root2->left,flag);
        return result2;
    }

    bool isSymmetric(TreeNode* root) {
        bool flag = true;
        check(root->left,root->right,flag);
        return flag;
    }
};