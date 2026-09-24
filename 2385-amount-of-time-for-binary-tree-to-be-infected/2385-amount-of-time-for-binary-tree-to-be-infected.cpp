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

    void traverse(TreeNode* root,map<TreeNode*,TreeNode*> &m,TreeNode* &temp,int target){
        if(root==NULL) return;
        if(root->val==target) temp = root;
        if(root->left!=NULL) m[root->left] = root;
        if(root->right!=NULL) m[root->right] = root;
        traverse(root->left,m,temp,target);
        traverse(root->right,m,temp,target);
    }

    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> m;
        TreeNode* temp = NULL;
        traverse(root,m,temp,start);
        queue<pair<TreeNode*,int>> q;
        q.push({temp,0});
        set<TreeNode*> s;
        s.insert(temp);
        int count = 0;
        int value = 0;
        while(q.size()>0){
            auto it = q.front();
            q.pop();
            TreeNode* temp = it.first;
            int curr = it.second;
            value = curr;
            if(temp->left!=NULL && s.find(temp->left)==s.end()){
                q.push({temp->left,curr+1});
                s.insert(temp->left);
            }
            if(temp->right!=NULL && s.find(temp->right)==s.end()){
                q.push({temp->right,curr+1});
                s.insert(temp->right);
            }
            if(m.find(temp)!=m.end() && s.find(m[temp])==s.end()){
                q.push({m[temp],curr+1});
                s.insert(m[temp]);
            }

        }
        return value;
    }
};