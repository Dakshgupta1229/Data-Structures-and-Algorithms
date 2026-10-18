/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> v;
        map<TreeNode*,TreeNode*> m;
        stack<TreeNode*> st;
        st.push(root);
        while(st.size()>0){
            TreeNode* temp = st.top();
            st.pop();
            if(temp->left!=NULL){
                st.push(temp->left);
                m[temp->left] = temp;
            }
            if(temp->right!=NULL){
                st.push(temp->right);
                m[temp->right] = temp;
            }
        }
        queue<pair<TreeNode*,int>> q;
        q.push({target,0});
        set<TreeNode*> s;
        s.insert(target);
        while(q.size()>0){
            auto it = q.front();
            q.pop();
            TreeNode* t = it.first;
            int value = it.second;
            if(value==k) v.push_back(t->val);
            if(m.find(t)!=m.end() && s.find(m[t])==s.end()){
                q.push({m[t],value+1});
                s.insert(m[t]);
            }
            if(t->left!=NULL && s.find(t->left)==s.end()){
                q.push({t->left,value+1});
                s.insert(t->left);
            }
            if(t->right!=NULL && s.find(t->right)==s.end()){
                q.push({t->right,value+1});
                s.insert(t->right);
            }
        }
        return v;
    }
};