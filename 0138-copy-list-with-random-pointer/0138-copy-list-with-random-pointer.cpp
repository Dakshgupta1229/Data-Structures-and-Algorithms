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
        Node* newHead = new Node(10);
        Node* t = newHead;
        Node* temp = head;
        while(temp!=NULL){
            Node* tt = new Node(temp->val);
            newHead->next = tt;
            newHead = newHead->next;
            temp = temp->next;
        }
        t = t->next;
        Node* newHead2 = new Node(10);
        Node* t2 = newHead2;
        while(head!=NULL && t!=NULL){
            newHead2->next = head;
            newHead2 = newHead2->next;
            head = head->next;
            newHead2->next = t;
            newHead2 = newHead2->next;
            t = t->next;
        }
        t2 = t2->next;
        Node* t3 = t2;
        while(t3!=NULL){
            Node* original_random = t3->random;
            if(original_random==NULL){
                t3->next->random = NULL;
            }
            else{
                t3->next->random = original_random->next;
            }
            t3 = t3->next->next;
        }
        Node* result1 = new Node(10);
        Node* r1 = result1;
        Node* result2 = new Node(10);
        Node* r2 = result2;
        while(t2!=NULL){
            result1->next = t2;
            result1 = result1->next;
            t2 = t2->next;
            result2->next = t2;
            result2 = result2->next;
            t2 = t2->next;
        }
        if(result1!=NULL) result1->next = NULL;
        if(result2!=NULL) result2->next = NULL;
        head = r1->next;

        return r2->next;
    }
};