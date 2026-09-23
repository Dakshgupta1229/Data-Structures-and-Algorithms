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
        Node* temp3 = new Node(10);
        Node* temp4 = temp3;
        while(t!=NULL && head!=NULL){
            temp3->next = head;
            temp3 = temp3->next;
            head = head->next;
            temp3->next = t;
            temp3 = temp3->next;
            t = t->next;
        }
        temp4 = temp4->next;
        Node* temp5 = temp4;
        while(temp5!=NULL){
            Node* t = temp5->random;
            if(t==NULL) temp5->next->random = NULL;
            else{
                temp5->next->random = t->next;
            }
            temp5 = temp5->next->next;
        }
        Node* temp6 = new Node(10);
        Node* tt6 = temp6;
        Node* temp7 = new Node(10);
        Node* tt7 = temp7;
        while(temp4!=NULL){
            temp6->next = temp4;
            temp6 = temp6->next;
            temp4 = temp4->next;
            temp7->next = temp4;
            temp7 = temp7->next;
            temp4 = temp4->next;
        }
        if(temp6!=NULL) temp6->next = NULL;
        if(temp7!=NULL) temp7->next = NULL;
        head = tt6->next;
        return tt7->next;

    }
};