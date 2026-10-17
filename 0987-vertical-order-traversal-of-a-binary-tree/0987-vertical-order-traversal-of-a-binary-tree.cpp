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
        vector<vector<int>> v;
        map<int,map<int,vector<int>>> m;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int count = 0;
        while(q.size()>0){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto it = q.front();
                q.pop();
                TreeNode* temp = it.first;
                int value = it.second;
                m[value][count].push_back(temp->val);
                if(temp->left!=NULL) q.push({temp->left,value-1});
                if(temp->right!=NULL) q.push({temp->right,value+1});
            }
            count++;
        }
        for(auto p:m){
            map<int,vector<int>> m1 = p.second;
            vector<int> v2;
            for(auto p1:m1){
                vector<int> v1 = p1.second;
                sort(v1.begin(),v1.end());
                for(int i=0;i<v1.size();i++) v2.push_back(v1[i]);
            }
            v.push_back(v2);
        }
        return v;
    }
};