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

    ListNode* merge(ListNode* list1,ListNode* list2){
        ListNode* temp = new ListNode(10);
        ListNode* t = temp;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            }
            else{
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
        }
        if(list1!=NULL) temp->next = list1;
        if(list2!=NULL) temp->next = list2;
        return t->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* temp = slow->next;
        slow->next = NULL;
        ListNode* list1 = sortList(head);
        ListNode* list2 = sortList(temp);
        ListNode* result = merge(list1,list2);
        return result;
    }
};