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
        ListNode* result = new ListNode(10);
        ListNode* r = result;
        int carry = 0;
        while(l1!=NULL && l2!=NULL){
            int sum = l1->val + l2->val + carry;
            int digit = sum%10;
            sum = sum/10;
            if(sum!=0) carry = sum;
            else carry = 0;
            ListNode* t = new ListNode(digit);
            result->next = t;
            result = result->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1!=NULL){
            int sum = l1->val + carry;
            int digit = sum%10;
            sum = sum/10;
            if(sum!=0) carry = sum;
            else carry = 0;
            ListNode* t = new ListNode(digit);
            result->next = t;
            result = result->next;
            l1 = l1->next;
        }
        while(l2!=NULL){
            int sum = l2->val + carry;
            int digit = sum%10;
            sum = sum/10;
            if(sum!=0) carry = sum;
            else carry = 0;
            ListNode* t = new ListNode(digit);
            result->next = t;
            result = result->next;
            l2 = l2->next;
        }
        if(carry!=0){
            ListNode* t = new ListNode(carry);
            result->next = t;
        }
        return r->next;
    }
};