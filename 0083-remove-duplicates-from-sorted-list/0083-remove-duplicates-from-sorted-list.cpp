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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newHead = new ListNode(1000);
        ListNode* t = newHead;
        ListNode* temp = head;
        while(temp!=NULL){
            if(temp->val!=newHead->val){
                newHead->next = temp;
                newHead = newHead->next;
            }
            temp = temp->next;
        }
        newHead->next = NULL;
        return t->next;
    }
};