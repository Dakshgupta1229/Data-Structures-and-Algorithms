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
        ListNode* curr = slow->next;
        slow->next = NULL;
        ListNode* temp = slow->next;
        ListNode* prev = NULL;
        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode* tt = new ListNode(10);
        ListNode* t = tt;
        while(head!=NULL && prev!=NULL){
            tt->next = head;
            tt = tt->next;
            head = head->next;
            tt->next = prev;
            tt = tt->next;
            prev = prev->next;
        }
        if(head!=NULL) tt->next = head;
        if(prev!=NULL) tt->next = prev;
        head = t->next;
    }
};