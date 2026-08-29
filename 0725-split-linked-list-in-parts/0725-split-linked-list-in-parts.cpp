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
            while(head!=NULL){
                ListNode* temp = head;
                head = head->next;
                temp->next = NULL;
                v.push_back(temp);
            }
            while(v.size()!=k) v.push_back(NULL);
        }
        else{
            int parts = n/k;
            int extra = n%k;
            int count = 1;
            ListNode* start = NULL;
            while(head!=NULL){
                if(count==1) start = head;
                if(extra>0 && count==(parts+1)){
                    ListNode* t = head;
                    head = head->next;
                    t->next = NULL;
                    v.push_back(start);
                    count = 1;
                    extra--;
                }
                else if(extra<=0 && count==parts){
                        ListNode* t = head;
                        head = head->next;
                        t->next = NULL;
                        v.push_back(start);
                    count = 1;
                }
                else{
                    head = head->next;
                    count++;
                }
            }
        }
        return v;
    }
};