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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        bool flag = false;
        for(int i=0;i<n+1;i++){
            if(fast==NULL){
                flag = true;
                break;
            }
            fast = fast->next;
        }
        ListNode* slow = head;
        while(fast!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        if(flag==true) return head->next;
        slow->next = slow->next->next;
        return head;
    }
};