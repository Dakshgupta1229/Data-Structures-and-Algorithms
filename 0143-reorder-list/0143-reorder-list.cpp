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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        ListNode* temp = slow->next;
        slow->next = NULL;
        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode* newHead = new ListNode(1000);
        ListNode* t = newHead;
        while(head!=NULL && prev!=NULL){
            newHead->next = head;
            newHead = newHead->next;
            head = head->next;
            newHead->next = prev;
            prev = prev->next;
            newHead = newHead->next;
        }
        if(head!=NULL) newHead->next = head;
        if(prev!=NULL) newHead->next = prev;
        head = t->next;
    }
};