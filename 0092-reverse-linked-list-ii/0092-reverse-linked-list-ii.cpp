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
            ListNode* first = NULL;
            ListNode* second = NULL;
            ListNode* third = NULL;
            ListNode* fourth = NULL;
            int count = 1;
            ListNode* temp = head;
            while(temp!=NULL){
                if(count==left-1) first = temp;
                if(count==left) second = temp;
                if(count==right) third = temp;
                if(count==right+1) fourth = temp;
                temp = temp->next;
                count++;
            }
            if(first!=NULL) first->next = NULL;
            if(third!=NULL) third->next = NULL;
        ListNode* prev = NULL;
        ListNode* curr = second;
        ListNode* t = second;
        while(curr!=NULL){
            t = curr->next;
            curr->next = prev;
            prev = curr;
            curr = t;
        }
        if(left==1){
            head->next = fourth;
            return prev;
        }
        first->next = prev;
        second->next = fourth;
        return head;
    }
};