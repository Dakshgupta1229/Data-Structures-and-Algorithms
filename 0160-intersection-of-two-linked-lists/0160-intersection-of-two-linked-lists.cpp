/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    int size(ListNode* head){
        int count = 0;
        while(head!=NULL){
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1 = size(headA);
        int n2 = size(headB);
        if(n1>n2){
            for(int i=0;i<n1-n2;i++) headA = headA->next;
        }
        if(n2>n1){
            for(int i=0;i<n2-n1;i++) headB = headB->next;
        }
        while(headA!=NULL && headB!=NULL){
            if(headA==headB) return headA;
            headA = headA->next;
            headB= headB->next;
        }
        return NULL;
    }
};