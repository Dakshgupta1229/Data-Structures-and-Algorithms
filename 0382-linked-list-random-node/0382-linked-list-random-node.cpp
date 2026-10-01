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
        this->n = size(head);
    }

    int size(ListNode* head){
        int count = 0;
        while(head!=NULL){
            head = head->next;
            count++;
        }
        return count;
    }
    
    int getRandom() {
        int low = 1;
        int high = n;
        int random = low + rand()%(high-low+1);
        int count = 1;
        ListNode* temp = head;
        while(temp!=NULL){
            if(count==random) return temp->val;
            temp = temp->next;
            count++;
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */