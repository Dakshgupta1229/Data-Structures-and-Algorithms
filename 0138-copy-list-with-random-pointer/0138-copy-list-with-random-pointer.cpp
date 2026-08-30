/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        map<Node*,Node*> m;
        while(temp!=NULL){
            Node* t = new Node(temp->val);
            m[temp] = t;
            temp = temp->next;
        }
        for(auto p:m){
            Node* first = p.first;
            Node* second = p.second;
            Node* first_next = first->next;
            second->next = m[first_next];
            Node* first_random = first->random;
            second->random = m[first_random];
        }
        return m[head];
    }
};