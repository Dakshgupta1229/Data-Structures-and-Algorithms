/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return root;
        queue<Node*> q;
        q.push(root);
        while(q.size()>0){
            int n = q.size();
            vector<Node*> v;
            for(int i=0;i<n;i++){
                Node* temp = q.front();
                q.pop();
                v.push_back(temp);
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            for(int i=0;i<v.size();i++){
                Node* temp = v[i];
                temp->next = NULL;
                if(i+1<v.size()){
                    Node* t = v[i+1];
                    temp->next = t;
                }
            }
        }
        return root;
    }
};