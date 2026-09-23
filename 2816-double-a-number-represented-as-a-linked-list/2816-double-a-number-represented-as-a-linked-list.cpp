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
        ListNode* t = newHead;
        int carry = 0;
        while(prev!=NULL){
            int sum = (2 * prev->val) + carry;
            int digit = sum%10;
            sum = sum/10;
            if(sum!=0) carry = sum;
            else carry = 0;
            ListNode* tt = new ListNode(digit);
            newHead->next = tt;
            newHead = newHead->next;
            prev = prev->next;
        }
        if(carry!=0){
            ListNode* tt = new ListNode(carry);
            newHead->next = tt;
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