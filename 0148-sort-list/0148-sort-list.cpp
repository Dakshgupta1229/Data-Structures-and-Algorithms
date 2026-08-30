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
        ListNode* result = new ListNode(100);
        ListNode* r = result;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
                result->next = list1;
                list1 = list1->next;
            }
            else{
                result->next = list2;
                list2 = list2->next;
            }
            result = result->next;
        }
        if(list1!=NULL) result->next = list1;
        if(list2!=NULL) result->next = list2;
        return r->next;
    }

    ListNode* find_middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* middle = find_middle(head);
        ListNode* first = head;
        ListNode* second = middle->next;
        middle->next = NULL;
        ListNode* l1 = sortList(first);
        ListNode* l2 = sortList(second);
        return merge(l1,l2);
    }
};