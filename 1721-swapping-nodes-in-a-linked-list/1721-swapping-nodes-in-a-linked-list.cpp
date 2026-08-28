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
    int size(ListNode* head){
        int count = 0;
        while(head!=NULL){
            count++;
            head = head->next;
        }
        return count;
    }

    ListNode* check(ListNode* head,int k){
        int count = 1;
        while(head!=NULL){
            if(count==k) return head;
            head = head->next;
            count++;
        }
        return NULL;
    }

    ListNode* swapNodes(ListNode* head, int k) {
        int n = size(head);
        ListNode* l1 = check(head,k);
        ListNode* l2 = check(head,n-k+1);
        int temp = l1->val;
        l1->val = l2->val;
        l2->val = temp;
        return head;
    }
};