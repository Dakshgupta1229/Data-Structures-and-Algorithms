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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newHead = new ListNode(10);
        ListNode* t = newHead;
        int carry = 0;
        while(l1!=NULL && l2!=NULL){
            int sum = l1->val + l2->val + carry;
            int ld = sum;
            if(sum>=10){
                ld = sum%10;
                sum = sum/10;
                carry = sum%10;
            }
            else carry = 0;
            ListNode* tt = new ListNode(ld);
            newHead->next = tt;
            newHead = newHead->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL){
            int sum = l1->val + carry;
            int ld = sum;
            if(sum>=10){
                ld = sum%10;
                sum = sum/10;
                carry = sum%10;
            }
            else carry = 0;
            ListNode* tt = new ListNode(ld);
            newHead->next = tt;
            newHead = newHead->next;
            l1 = l1->next;
        }
        while(l2!=NULL){
            int sum = l2->val + carry;
            int ld = sum;
            if(sum>=10){
                ld = sum%10;
                sum = sum/10;
                carry = sum%10;
            }
            else carry = 0;
            ListNode* tt = new ListNode(ld);
            newHead->next = tt;
            newHead = newHead->next;
            l2 = l2->next;
        }
        if(carry!=0){
            ListNode* tt = new ListNode(carry);
            newHead->next = tt;
        }
        return t->next;
    }
};