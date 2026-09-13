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

    void check(TreeNode* root,int &sum,int &cnt){
        if(root==NULL) return;
        sum = sum + root->val;
        cnt++;
        check(root->left,sum,cnt);
        check(root->right,sum,cnt);
    }

    void traverse(TreeNode* root,int &count){
        if(root==NULL) return;
        int sum = 0;
        int cnt = 0;
        check(root,sum,cnt);
        if(root->val==(sum/cnt)) count++;
        traverse(root->left,count);
        traverse(root->right,count);
    }

    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        traverse(root,count);
        return count;
    }
};