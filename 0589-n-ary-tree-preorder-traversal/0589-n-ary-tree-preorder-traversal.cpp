/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    void traverse(Node* root,vector<int> &v){
        if(root==NULL) return;
        v.push_back(root->val);
        vector<Node*> children = root->children;
        for(int i=0;i<children.size();i++){
            traverse(children[i],v);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> v;
        traverse(root,v);
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        return v;
    }
};