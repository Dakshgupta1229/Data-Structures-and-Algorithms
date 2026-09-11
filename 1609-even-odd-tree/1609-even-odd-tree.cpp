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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool result = true;
        int level = 0;
        while(q.size()>0){
            if(result==false) break;
            int n = q.size();
            vector<int> v;
            for(int i=0;i<n;i++){
                TreeNode* temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            if(level%2==0){
                for(int i=1;i<v.size();i++){
                    if(v[i]>v[i-1] && v[i]%2!=0 && v[i-1]%2!=0){}
                    else{
                        result = false;
                        break;
                    }
                }
                if(v.size()>0 && v[0]%2==0){
                    result = false;
                    break;
                }
            }
            else{
                for(int i=1;i<v.size();i++){
                    if(v[i]<v[i-1] && v[i]%2==0 && v[i-1]%2==0){}
                    else{
                        result = false;
                        break;
                    }
                }
                if(v.size()>0 && v[0]%2!=0){
                    result = false;
                    break;
                }
            }
            level++;
        }
        return result;
    }
};