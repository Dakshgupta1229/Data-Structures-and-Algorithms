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
        int count = 1;
        ListNode* odd = new ListNode(100);
        ListNode* o = odd;
        ListNode* even = new ListNode(100);
        ListNode* e = even;
        while(head!=NULL){
            if(count%2!=0){
                odd->next = head;
                odd = odd->next;
                head = head->next;
            }
            else{
                even->next = head;
                even = even->next;
                head = head->next;
            }
            count++;
        }
        even->next = NULL;
        odd->next = e->next;
        return o->next;
    }
};