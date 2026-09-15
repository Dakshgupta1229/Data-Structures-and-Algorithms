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

    ListNode* swapNodes(ListNode* head, int k) {
        int n = size(head);
        ListNode* temp = head;
        int count = 1;
        ListNode* first = NULL;
        ListNode* second = NULL;
        for(int i=0;i<n;i++){
            if(count==k) first = temp;
            if(count==n-k+1) second = temp;
            temp = temp->next;
            count++;
        }
        int value = first->val;
        first->val = second->val;
        second->val = value;
        return head;
    }
};