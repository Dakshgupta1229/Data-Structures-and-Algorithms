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
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = slow->next;
        slow->next = NULL;
        ListNode* curr = temp;
        ListNode* prev = NULL;
        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode* result = new ListNode(10);
        ListNode* r = result;
        while(head!=NULL && prev!=NULL){
            result->next = head;
            result = result->next;
            head = head->next;
            result->next = prev;
            result = result->next;
            prev = prev->next;
        }
        if(head!=NULL) result->next = head;
        if(prev!=NULL) result->next = prev;
        head = r->next;
    }
};