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
        ListNode* temp2 = head;
        while(temp2!=NULL){
            if(count==left-1) first = temp2;
            if(count==left) second = temp2;
            if(count==right) third = temp2;
            if(count==right+1) fourth = temp2;
            temp2 = temp2->next;
            count++;
        }
        if(left==1){
            third->next = NULL;
            ListNode* s = second;
            ListNode* prev = NULL;
            ListNode* curr = second;
            ListNode* temp = second;
            while(curr!=NULL){
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }
            if(s!=NULL) s->next = fourth;
            return prev;

        }

        first->next = NULL;
        third->next = NULL;
        ListNode* save = second;
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
        save->next = fourth;

        return head;
    }
};