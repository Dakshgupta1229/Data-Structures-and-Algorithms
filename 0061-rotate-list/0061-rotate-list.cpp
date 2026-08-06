/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    int size(ListNode* head){
        int count = 0;
        while(head!=NULL){
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        int n = size(head);
        if(head==NULL || k==0) return head;
        k = k%n;
        if(k==0) return head;
        ListNode* temp = head;
        for(int i=0;i<n-k-1;i++) temp = temp->next;
        ListNode* newHead = temp->next;
        ListNode* t = newHead;
        temp->next = NULL;
        while(t!=NULL && t->next!=NULL){
            t = t->next;
        }
        t->next = head;
        return newHead;
    }
};