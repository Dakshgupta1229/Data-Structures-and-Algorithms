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
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> m;
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* target= NULL;
        while(st.size()>0){
            TreeNode* temp = st.top();
            st.pop();
            if(temp->val==start) target = temp;
            if(temp->left!=NULL){
                m[temp->left] = temp;
                st.push(temp->left);
            }
            if(temp->right!=NULL){
                m[temp->right] = temp;
                st.push(temp->right);
            }
        }
        queue<pair<TreeNode*,int>> q;
        q.push({target,0});
        set<TreeNode*> s;
        s.insert(target);
        int ans = 0;
        while(q.size()>0){
            auto it = q.front();
            q.pop();
            TreeNode* temp = it.first;
            int value = it.second;
            ans = value;
            if(m.find(temp)!=m.end() && s.find(m[temp])==s.end()){
                q.push({m[temp],value+1});
                s.insert(m[temp]);
            }
            if(temp->left!=NULL && s.find(temp->left)==s.end()){
                q.push({temp->left,value+1});
                s.insert(temp->left);
            }
            if(temp->right!=NULL && s.find(temp->right)==s.end()){
                q.push({temp->right,value+1});
                s.insert(temp->right);
            }
        }
        return ans;

    }
};