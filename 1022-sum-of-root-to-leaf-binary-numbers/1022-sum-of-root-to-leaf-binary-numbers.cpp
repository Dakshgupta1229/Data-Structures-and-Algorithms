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

    void check(TreeNode* root,vector<string> &v,string str){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            str = str + to_string(root->val);
            v.push_back(str);
            return;
        }
        str = str + to_string(root->val);
        check(root->left,v,str);
        check(root->right,v,str);
    }

    int sumRootToLeaf(TreeNode* root) {
        vector<string> v;
        check(root,v,"");
        int result = 0;
        for(int i=0;i<v.size();i++){
            string str = v[i];
            int num = 0;
            int idx = 0;
            for(int j=str.size()-1;j>=0;j--){
                num = num + (pow(2,idx) * (str[j]-48));
                idx++;
            }
            result = result + num;
        }
        return result;
    }
};