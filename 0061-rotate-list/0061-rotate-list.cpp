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
            head = head->next;
            count++;
        }
        return count;
    }

    ListNode* rotateRight(ListNode* head, int k) {
        int n = size(head);
        if(n==0) return NULL;
        k = k%n;
        if(k==0) return head;
        ListNode* temp = head;
        for(int i=0;i<n-k-1;i++) temp = temp->next;
        ListNode* temp2 = temp->next;
        temp->next = NULL;
        ListNode* temp3 = temp2;
        while(temp3->next!=NULL) temp3 = temp3->next;
        temp3->next = head;
        return temp2;
    }
};