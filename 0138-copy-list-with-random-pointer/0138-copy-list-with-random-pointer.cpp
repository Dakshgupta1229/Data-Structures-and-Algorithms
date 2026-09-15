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
        Node* copy = new Node(10);
        Node* t = copy;
        while(temp!=NULL){
            Node* tt = new Node(temp->val);
            copy->next = tt;
            copy = copy->next;
            temp = temp->next;
        }
        t = t->next;

        Node* temp2 = new Node(10);
        Node* temp3 = temp2;
        while(head!=NULL && t!=NULL){
            temp2->next = head;
            head = head->next;
            temp2 = temp2->next;
            temp2->next = t;
            t = t->next;
            temp2 = temp2->next;
        }
        temp3 = temp3->next;
        Node* temp8 = temp3;
        while(temp3!=NULL){
            Node* r = temp3->random;
            if(r==NULL) temp3->next->random = r;
            else temp3->next->random = r->next;
            temp3 = temp3->next->next;
        }
        Node* temp4 = new Node(10);
        Node* temp5 = temp4;
        Node* temp6 = new Node(10);
        Node* temp7 = temp6;
        while(temp8!=NULL){
            temp4->next = temp8;
            temp8 = temp8->next;
            temp4 = temp4->next;
            temp6->next = temp8;
            temp8 = temp8->next;
            temp6 = temp6->next;
        }
        temp4->next = NULL;
        temp6->next = NULL;
        head = temp5->next;
        return temp7->next;
    }
};