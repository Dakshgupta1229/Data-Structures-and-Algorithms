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

    int left_tree(TreeNode* root){
        int count = 0;
        while(root!=NULL){
            root = root->left;
            count++;
        }
        return count;
    }

    int right_tree(TreeNode* root){
        int count = 0;
        while(root!=NULL){
            root = root->right;
            count++;
        }
        return count;
    }

    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lt = left_tree(root);
        int rt = right_tree(root);
        if(lt==rt) return pow(2,lt) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};