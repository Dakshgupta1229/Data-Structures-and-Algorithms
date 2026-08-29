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

    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = size(head);
        int parts = n/k;
        ListNode* newHead = NULL;
        ListNode* track = head;
        ListNode* temp = head;
        ListNode* track2 = head;
        for(int i=0;i<parts;i++){
            ListNode* c = temp;
            for(int j=0;j<k-1;j++){
                temp = temp->next;
            }
            ListNode* tt = temp;
            temp = temp->next;
            track2 = temp;
            tt->next = NULL;
            ListNode* prev = NULL;
            ListNode* curr = c;
            ListNode* temp2 = c;
            while(curr!=NULL){
                temp2 = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp2;
            }
            if(newHead==NULL) newHead = prev;
            else{
                track->next = prev;
                track = c;
            }
        }
         track->next = temp;
        return newHead;
    }
};