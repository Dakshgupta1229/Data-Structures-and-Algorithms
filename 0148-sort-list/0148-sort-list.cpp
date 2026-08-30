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

    ListNode* find_middle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* result = new ListNode(100);
        ListNode* r = result;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<l2->val){
                result->next = l1;
                l1 = l1->next;
            }
            else{
                result->next = l2;
                l2 = l2->next;
            }
            result = result->next;
        }
        if(l1!=NULL) result->next = l1;
        if(l2!=NULL) result->next = l2;
        return r->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* middle = find_middle(head);
        ListNode* right = middle->next;
        middle->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(right);
        return merge(l1,l2);
    }
};