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
            ListNode* temp = new ListNode(1000);
            ListNode* t = temp;
            while(temp1!=NULL && temp2!=NULL){
                if(temp1->val<=temp2->val){
                    temp->next = temp1;
                    temp = temp->next;
                    temp1 = temp1->next;
                }
                else{
                    temp->next = temp2;
                    temp = temp->next;
                    temp2 = temp2->next;
                }
            }
            if(temp1!=NULL) temp->next = temp1;
            if(temp2!=NULL) temp->next = temp2;
            lists.push_back(t->next);
        }
        return lists[0];
    }
};