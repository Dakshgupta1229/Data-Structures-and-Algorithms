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

    void traverse(TreeNode* root,int vertical,int level,map<int,map<int,vector<int>>> &m){
        if(root==NULL) return;
        m[vertical][level].push_back(root->val);
        traverse(root->left,vertical-1,level+1,m);
        traverse(root->right,vertical+1,level+1,m);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> v;
        map<int,map<int,vector<int>>> m;
        traverse(root,0,0,m);
        for(auto p:m){
            int vertical = p.first;
            map<int,vector<int>> m1 = p.second;
            // cout<<vertical<<" -> "<<endl;
            vector<int> v2;
            for(auto p1:m1){
                // cout<<"Level: "<<p1.first<<endl;
                vector<int> v1 = p1.second;
                sort(v1.begin(),v1.end());
                for(int i=0;i<v1.size();i++){
                    v2.push_back(v1[i]);
                }
            }
            v.push_back(v2);
        }
        return v;
    }
};