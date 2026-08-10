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
        int count = 1;
        ListNode* temp1;
        ListNode* temp2;
        ListNode* temp = head;
        while(temp!=NULL){
            if(count==k) temp1 = temp;
            if(count==n-k+1) temp2 = temp;
            temp = temp->next;
            count++;
        }
        swap(temp1->val,temp2->val);
        return head;
    }
};