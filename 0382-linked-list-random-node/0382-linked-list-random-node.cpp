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
    ListNode* head;
    int n;
    Solution(ListNode* head) {
        this->head = head;
        ListNode* temp = head;
        int count = 0;
        while(temp!=NULL){
            count++;
            temp = temp->next;
        }
        this->n = count;
    }

    int getAtIdx(ListNode* head,int idx){
        int count = 1;
        while(head!=NULL){
            if(idx==count) return head->val;
            head = head->next;
            count++;
        }
        return -1;
    }
    
    int getRandom() {
        int low = 1;
        int high = n;
        int random = low + rand()%(high-low+1);
        return getAtIdx(head,random);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */