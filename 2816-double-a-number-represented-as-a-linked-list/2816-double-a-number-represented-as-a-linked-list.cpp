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
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* temp = head;
        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode* newHead = new ListNode(10);
        ListNode* tt = newHead;
        int carry = 0;
        while(prev!=NULL){
            int sum = (2 * prev->val) + carry;
            int ld = sum;
            if(sum>=10){
                ld = sum%10;
                sum = sum/10;
                carry = sum%10;
            }
            else carry = 0;
            ListNode* t = new ListNode(ld);
            newHead->next = t;
            newHead = newHead->next;
            prev = prev->next;
        }
        if(carry!=0){
            ListNode* t = new ListNode(carry);
            newHead->next = t;
        }
        prev = NULL;
        curr = tt->next;
        temp = tt->next;
        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};