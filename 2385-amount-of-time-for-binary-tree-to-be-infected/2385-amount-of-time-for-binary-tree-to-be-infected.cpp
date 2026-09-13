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

    void traverse(TreeNode* root,int start,TreeNode* &temp,map<TreeNode*,TreeNode*> &m){
        if(root==NULL) return;
        if(root->left!=NULL) m[root->left] = root;
        if(root->right!=NULL) m[root->right] = root;
        if(root->val==start){
            temp = root;
        }
        traverse(root->left,start,temp,m);
        traverse(root->right,start,temp,m);
    }

    int amountOfTime(TreeNode* root, int start) {
        TreeNode* temp = NULL;
        map<TreeNode*,TreeNode*> m;
        traverse(root,start,temp,m);
        queue<pair<TreeNode*,int>> q;
        q.push({temp,0});
        set<TreeNode*> s;
        s.insert(temp);
        int result = 0;
        while(q.size()>0){
            auto it = q.front();
            q.pop();
            TreeNode* tmp = it.first;
            int value = it.second;
            result = value;
            if(tmp->left!=NULL && s.find(tmp->left)==s.end()){
                q.push({tmp->left,value+1});
                s.insert(tmp->left);
            }
            if(tmp->right!=NULL && s.find(tmp->right)==s.end()){
                q.push({tmp->right,value+1});
                s.insert(tmp->right);
            }
            if(m.find(tmp)!=m.end() && s.find(m[tmp])==s.end()){
                q.push({m[tmp],value+1});
                s.insert(m[tmp]);
            }
        }
        return result;
    }
};