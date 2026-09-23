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
        ListNode* t = head;
        int count = 1;
        while(t!=NULL){
            if(count==left-1) first = t;
            if(count==left) second = t;
            if(count==right) third = t;
            if(count==right+1) fourth = t;
            t = t->next;
            count++;
        }
        if(left==1){
            ListNode* prev = NULL;
            ListNode* temp = second;
            ListNode* curr = second;
            third->next = NULL;
            while(curr!=NULL){
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            ListNode* temp2 = prev;
            while(temp2->next!=NULL) temp2 = temp2->next;
            temp2->next = fourth;
            return prev;
        }

        first->next = NULL;
        third->next = NULL;
        ListNode*prev = NULL;
        ListNode* curr = second;
        ListNode* temp = NULL;
        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode* temp2 = prev;
        while(temp2->next!=NULL) temp2 = temp2->next;
        first->next = prev;
        temp2->next = fourth;
        return head;

    }
};