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
        vector<TreeNode*> v;
        stack<TreeNode*> st;
        st.push(root);
        while(st.size()>0){
            TreeNode* temp = st.top();
            st.pop();
            v.push_back(temp);
            if(temp->right!=NULL) st.push(temp->right);
            if(temp->left!=NULL) st.push(temp->left);
        }
        TreeNode* newroot = new TreeNode(10);
        TreeNode* t = newroot;
        for(int i=0;i<v.size();i++){
            TreeNode* temp = v[i];
            temp->left = NULL;
            temp->right = NULL;
            newroot->right = temp;
            newroot = newroot->right;
        }
        root = t->right;
    }
};