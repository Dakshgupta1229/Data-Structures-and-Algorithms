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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> result;
        map<int,map<int,vector<int>>> m;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int count = 0;
        while(q.size()>0){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto it = q.front();
                TreeNode* temp = it.first;
                int curr = it.second;
                q.pop();
                m[curr][count].push_back(temp->val);
                if(temp->left!=NULL) q.push({temp->left,curr-1});
                if(temp->right!=NULL) q.push({temp->right,curr+1});
            }
            count++;
        }
        for(auto p:m){
            map<int,vector<int>> m2 = p.second;
            vector<int> v1;
            for(auto p1:m2){
                vector<int> v = p1.second;
                sort(v.begin(),v.end());
                for(int i=0;i<v.size();i++) v1.push_back(v[i]);
            }
            result.push_back(v1);
        }
        return result;
    }
};