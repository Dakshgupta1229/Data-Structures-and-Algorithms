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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* newHead = new ListNode(10);
        ListNode* t = newHead;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
                newHead->next = list1;
                list1 = list1->next;
            }
            else{
                newHead->next = list2;
                list2 = list2->next;
            }
            newHead = newHead->next;
        }
        if(list1!=NULL) newHead->next = list1;
        if(list2!=NULL) newHead->next = list2;
        return t->next;
    }
};