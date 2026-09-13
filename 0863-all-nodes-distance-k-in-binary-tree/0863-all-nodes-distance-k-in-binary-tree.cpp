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

    void traverse(TreeNode* root,map<TreeNode*,TreeNode*> &m){
        if(root==NULL) return;
        if(root->left!=NULL) m[root->left] = root;
        if(root->right!=NULL) m[root->right] = root;
        traverse(root->left,m);
        traverse(root->right,m);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> v;
        set<TreeNode*> s;
        map<TreeNode*,TreeNode*> m;
        traverse(root,m);
        queue<pair<TreeNode*,int>> q;
        q.push({target,0});
        s.insert(target);
        while(q.size()>0){
            auto it = q.front();
            q.pop();
            TreeNode* temp = it.first;
            int value = temp->val;
            int distance = it.second;
            if(distance==k) v.push_back(value);
            if(temp->left!=NULL && s.find(temp->left)==s.end()){
                q.push({temp->left,distance+1});
                s.insert(temp->left);
            }
            if(temp->right!=NULL && s.find(temp->right)==s.end()){
                q.push({temp->right,distance+1});
                s.insert(temp->right);
            }
            if(m.find(temp)!=m.end() && s.find(m[temp])==s.end()){
                q.push({m[temp],distance+1});
                s.insert(m[temp]);
            }
        }
        return v;
    }
};