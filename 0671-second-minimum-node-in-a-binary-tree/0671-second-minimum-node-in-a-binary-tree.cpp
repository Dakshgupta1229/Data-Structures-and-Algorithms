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

    void traverse(TreeNode* root,set<int> &s){
        if(root==NULL) return;
        s.insert(root->val);
        traverse(root->left,s);
        traverse(root->right,s);
    }

    int findSecondMinimumValue(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return -1;
        set<int> s;
        traverse(root,s);
        int count = 1;
        int min = -1;
        for(auto p:s){
            if(count==2){
                min = p;
                break;
            }
            count++;
        }
        return min;
    }
};