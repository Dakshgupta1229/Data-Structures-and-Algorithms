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
        Node* temp = new Node(10);
        Node* t = temp;
        Node* temp2 = head;
        while(temp2!=NULL){
            Node* tt = new Node(temp2->val);
            temp->next = tt;
            temp = temp->next;
            temp2 = temp2->next;
        }
        t = t->next;
        Node* result = new Node(10);
        Node* r = result;
        while(head!=NULL && t!=NULL){
            result->next = head;
            result = result->next;
            head = head->next;
            result->next = t;
            result = result->next;
            t = t->next;
        }
        r = r->next;
        Node* temp3 = r;
        while(temp3!=NULL){
            if(temp3->random==NULL) temp3->next->random = NULL;
            else{
                temp3->next->random = temp3->random->next;
            }
            temp3 = temp3->next->next;
        }

        Node* first = new Node(10);
        Node* f = first;
        Node* second = new Node(10);
        Node* s = second;
        while(r!=NULL){
            first->next = r;
            first = first->next;
            r = r->next;
            second->next = r;
            second = second->next;
            r = r->next;
        }
        first->next = NULL;
        second->next = NULL;
        head = f->next;
        return s->next;

    }
};