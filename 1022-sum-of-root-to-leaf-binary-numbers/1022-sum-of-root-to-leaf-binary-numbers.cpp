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
            int num = 0;
            int idx = 0;
            for(int i=str.size()-1;i>=0;i--){
                num = num + (pow(2,idx) * (int)(str[i]-48));
                idx++;
            }
            sum = sum + num;
            return;
        }
        str = str + to_string(root->val);
        traverse(root->left,str,sum);
        traverse(root->right,str,sum);
    }

    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        traverse(root,"",sum);
        return sum;
    }
};