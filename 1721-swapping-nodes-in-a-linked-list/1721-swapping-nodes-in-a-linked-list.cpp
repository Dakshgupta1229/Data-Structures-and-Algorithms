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
        ListNode* temp1 = NULL;
        ListNode* temp2 = NULL;
        int count = 1;
        ListNode* temp = head;
        while(temp!=NULL){
            if(count==k) temp1 = temp;
            if(count==n-k+1) temp2 = temp;
            temp = temp->next;
            count++;
        }
        int value = temp1->val;
        temp1->val = temp2->val;
        temp2->val = value;
        return head;
    }
};