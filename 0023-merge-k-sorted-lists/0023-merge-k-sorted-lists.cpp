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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        while(lists.size()>1){
            ListNode* temp1 = lists[lists.size()-1];
            ListNode* temp2 = lists[lists.size()-2];
            lists.pop_back();
            lists.pop_back();
            ListNode* newHead = new ListNode(10);
            ListNode* t = newHead;
            while(temp1!=NULL && temp2!=NULL){
                if(temp1->val<temp2->val){
                    newHead->next = temp1;
                    temp1 = temp1->next;
                }
                else{
                    newHead->next = temp2;
                    temp2 = temp2->next;
                }
                newHead = newHead->next;
            }
            if(temp1!=NULL) newHead->next = temp1;
            if(temp2!=NULL) newHead->next = temp2;
            lists.push_back(t->next);
        }
        return lists[0];
    }
};