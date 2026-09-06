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
        vector<Node*> v1 = root->children;
        for(int i=0;i<v1.size();i++){
            traverse(v1[i],v);
        }
        v.push_back(root->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> v;
        traverse(root,v);
        return v;
    }
};