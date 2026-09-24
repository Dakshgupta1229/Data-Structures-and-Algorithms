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
    void flatten(TreeNode* root) {
        if(root==NULL) return;
        stack<TreeNode*> st;
        st.push(root);
        vector<TreeNode*> v;
        while(st.size()>0){
            TreeNode* temp = st.top();
            st.pop();
            v.push_back(temp);
            if(temp->right!=NULL) st.push(temp->right);
            if(temp->left!=NULL) st.push(temp->left);
        }
        TreeNode* temp = v[0];
        root = temp;
        for(int i=1;i<v.size();i++){
            temp->right = v[i];
            temp->left = NULL;
            temp = v[i];
        }
    }
};