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
    ListNode* doubleIt(ListNode* head) {
        ListNode* newHead = new ListNode(1000);
        ListNode* t = newHead;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp = head;
        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        int carry = 0;
        while(prev!=NULL){
            int sum = 2 * prev->val + carry;
            int last_digit = sum%10;
            if(sum>=10){
                sum = sum/10;
                carry = sum;
            }
            else carry = 0;
            ListNode* t = new ListNode(last_digit);
            newHead->next = t;
            newHead = newHead->next;
            prev = prev->next;
        }
        if(carry!=0){
            ListNode* t = new ListNode(carry);
            newHead->next = t;
        }
        prev = NULL;
        curr = t->next;
        temp = t->next;
        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};