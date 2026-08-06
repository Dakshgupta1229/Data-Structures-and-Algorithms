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
        ListNode* t = new ListNode(1000);
        ListNode* newNode = t;
        ListNode* temp = head;
        while(temp!=NULL){
            if(t->val!=temp->val){
                t->next = temp;
                t = t->next;
            }
            temp = temp->next;
        }
        t->next = NULL;
        return newNode->next;
    }
};