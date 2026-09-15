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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(10);
        ListNode* l = less;
        ListNode* greater = new ListNode(10);
        ListNode* g = greater;
        while(head!=NULL){
            if(head->val<x){
                less->next = head;
                less = less->next;
            }
            else{
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }
        less->next = g->next;
        greater->next = NULL;
        return l->next;

    }
};