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
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* target = NULL;
        while(q.size()>0){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->val==start) target = temp;
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
        int rst = 0;
        while(q1.size()>0){
            auto it = q1.front();
            q1.pop();
            TreeNode* temp = it.first;
            int cnt = it.second;
            rst = cnt;
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
        
        return rst;
    }
};