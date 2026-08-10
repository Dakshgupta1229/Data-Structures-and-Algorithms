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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(10);
        ListNode* o = odd;
        ListNode* even = new ListNode(10);
        ListNode* e = even;
        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL){
            if(count%2==0){
                odd->next = temp;
                odd = odd->next;
            }
            else{
                even->next = temp;
                even = even->next;
            }
            count++;
            temp = temp->next;
        }
        even->next = NULL;
        odd->next = e->next;
        return o->next;
    }
};