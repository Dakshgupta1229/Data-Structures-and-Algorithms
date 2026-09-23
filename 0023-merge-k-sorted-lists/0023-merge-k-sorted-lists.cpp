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

    ListNode* merge(ListNode* list1,ListNode* list2){
        ListNode* list = new ListNode(10);
        ListNode* l = list;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
                list->next = list1;
                list = list->next;
                list1 = list1->next;
            }
            else{
                list->next = list2;
                list = list->next;
                list2 = list2->next;
            }
        }
        if(list1!=NULL) list->next = list1;
        if(list2!=NULL) list->next = list2;
        return l->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        while(lists.size()>1){
            ListNode* temp1 = lists[lists.size()-1];
            ListNode* temp2 = lists[lists.size()-2];
            lists.pop_back();
            lists.pop_back();
            ListNode* list = merge(temp1,temp2);
            lists.push_back(list);
        }
        return lists[0];
    }
};