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
        if(k==0) return {target->val};
        map<TreeNode*,TreeNode*> m;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left!=NULL){
                m[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                m[temp->right] = temp;
                q.push(temp->right);
            }
        }
        set<TreeNode*> s;
        queue<pair<TreeNode*,int>> q1;
        q1.push({target,0});
        s.insert(target);
        while(q1.size()>0){
            auto it = q1.front();
            TreeNode* temp = it.first;
            int cnt = it.second;
            if(cnt==k) break;
            q1.pop();
            if(m[temp]!=NULL && s.find(m[temp])==s.end()){
                q1.push({m[temp],cnt+1});
                s.insert(m[temp]);
            }
            if(temp->left!=NULL && s.find(temp->left)==s.end()){
                q1.push({temp->left,cnt+1});
                s.insert(temp->left);
            }
            if(temp->right!=NULL && s.find(temp->right)==s.end()){
                q1.push({temp->right,cnt+1});
                s.insert(temp->right);
            }
        }
        vector<int> v;
        while(q1.size()>0){
            auto it = q1.front();
            q1.pop();
            if (it.second==k) v.push_back(it.first->val);
        }

        return v;
    }
};