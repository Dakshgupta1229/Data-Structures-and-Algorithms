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
        ListNode* temp = head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode* result = new ListNode(100);
        ListNode* r = result;
        int carry = 0;
        while(prev!=NULL){
            int sum = (2 * prev->val) + carry;
            int digit = sum%10;
            sum = sum/10;
            if(sum!=0) carry = sum;
            else carry = 0;
            ListNode* t = new ListNode(digit);
            result->next = t;
            result = result->next;
            prev = prev->next;
        }
        if(carry!=0) result->next = new ListNode(carry);
        temp = r->next;
        curr = r->next;
        prev = NULL;
        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;

    }
};