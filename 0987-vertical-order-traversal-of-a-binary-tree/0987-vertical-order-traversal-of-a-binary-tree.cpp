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
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        map<int,map<int,vector<int>>> m;
        int level = 0;
        while(q.size()>0){
            int n = q.size();
            for(int i=0;i<n;i++){
                auto it = q.front();
                q.pop();
                TreeNode* temp = it.first;
                int vertical = it.second;
                m[vertical][level].push_back(temp->val);
                if(temp->left!=NULL) q.push({temp->left,vertical-1});
                if(temp->right!=NULL) q.push({temp->right,vertical+1});
            }
            level++;
        }
        for(auto p:m){
            map<int,vector<int>> m1 = p.second;
            vector<int> v2;
            for(auto p1:m1){
                cout<<p1.first<<" -> Level"<<endl;
                vector<int> v1 = p1.second;
                sort(v1.begin(),v1.end());
                for(int i=0;i<v1.size();i++) v2.push_back(v1[i]);
            }
            v.push_back(v2);
        }
        return v;
    }
};