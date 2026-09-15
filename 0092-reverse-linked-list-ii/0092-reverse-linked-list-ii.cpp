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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left==right) return head;
        ListNode* newHead = head;
        ListNode* first = NULL;
        ListNode* second = NULL;
        ListNode* third = NULL;
        ListNode* fourth = NULL;
        int count = 1;
        while(head!=NULL){
            if(count==left-1) first = head;
            if(count==left) second = head;
            if(count==right) third = head;
            if(count==right+1) fourth = head;
            count++;
            head = head->next;
        }
        if(left==1){
            third->next = NULL;
            ListNode* tt = second;
            ListNode* prev = NULL;
            ListNode* curr = second;
            ListNode* temp = second;
            while(curr!=NULL){
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            tt->next = fourth;
            return prev;
        }
        first->next = NULL;
        third->next = NULL;
        ListNode* prev = NULL;
        ListNode* curr = second;
        ListNode* temp = second;
        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        first->next = prev;
        ListNode* t = prev;
        while(t->next!=NULL){
            t = t->next;
        }
        t->next = fourth;
        return newHead;

    }
};