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
        ListNode* odd = new ListNode(1000);
        ListNode* o = odd;
        ListNode* even = new ListNode(1000);
        ListNode* e = even;
        int count = 0;
        while(head!=NULL){
            if(count%2==0){
                odd->next = head;
                odd = odd->next;
            }
            else{
                even->next = head;
                even = even->next;
            }
            head = head->next;
            count++;
        }
        even->next = NULL;
        odd->next = e->next;
        return o->next;
    }
};