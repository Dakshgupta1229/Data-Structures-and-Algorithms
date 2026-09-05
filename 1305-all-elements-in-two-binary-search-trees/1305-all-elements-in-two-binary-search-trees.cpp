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

    void traverse(TreeNode* root,vector<int> &v1){
        if(root==NULL) return;
        traverse(root->left,v1);
        v1.push_back(root->val);
        traverse(root->right,v1);
    }

    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v;
        vector<int> v1;
        vector<int> v2;
        traverse(root1,v1);
        traverse(root2,v2);
        int i=0;
        int j=0;
        while(i<v1.size() && j<v2.size()){
            if(v1[i]<v2[j]){
                v.push_back(v1[i]);
                i++;
            }
            else{
                v.push_back(v2[j]);
                j++;
            }
        }
        while(i<v1.size()){
            v.push_back(v1[i]);
            i++;
        }
        while(j<v2.size()){
            v.push_back(v2[j]);
            j++;
        }
        return v;
    }
};