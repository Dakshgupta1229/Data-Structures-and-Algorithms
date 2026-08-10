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

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> v;
        int n = size(head);
        if(n<=k){
            ListNode* temp = head;
            while(temp!=NULL){
                ListNode* t = new ListNode(temp->val);
                v.push_back(t);
                temp = temp->next;
            }
            while(v.size()!=k){
                v.push_back(NULL);
            }
            return v;
        }
        int parts = n/k;
        int extra = n%k;
        ListNode * temp = head;
        int count = 1;
        ListNode* t = head;
        int pt = 0;
        while(temp!=NULL){
            if(extra>0) pt = parts + 1;
            else pt = parts;
            if(count==1) t = temp;
            if(count==pt){
                ListNode* tt = temp->next;
                temp->next = NULL;
                temp = tt;
                count = 1;
                v.push_back(t);
                t = temp;
                if(extra>0) extra--;
            }
            else{
                temp = temp->next;
                count++;
            }
        }
        return v;
    }
};