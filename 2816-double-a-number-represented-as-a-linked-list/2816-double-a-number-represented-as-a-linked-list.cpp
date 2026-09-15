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
        int carry = 0;
        ListNode* t = NULL;
        ListNode* newHead = prev;
        while(prev!=NULL){
            if(prev->next==NULL) t = prev;
            int sum = 2 * prev->val + carry;
            int digit = sum%10;
            if(sum>=10){
                sum = sum/10;
                carry = sum%10;
            }
            else carry = 0;
            prev->val = digit;
            prev = prev->next;
        }
        if(carry!=0){
            ListNode* tt = new ListNode(carry);
            t->next = tt;
        }
        prev = NULL;
        curr = newHead;
        temp = newHead;
        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
};