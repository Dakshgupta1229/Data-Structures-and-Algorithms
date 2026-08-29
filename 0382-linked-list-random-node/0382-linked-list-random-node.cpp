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
    int size;
    Solution(ListNode* head) {
        this->head = head;
            int count = 0;
            ListNode* temp = head;
            while(temp!=NULL){
                count++;
                temp = temp->next;
            }
            this->size = count;
    }
    
    int getRandom() {
        int low = 1;
        int high = size;
        int random_number = low + rand() % (high-low+1);
        int count = 1;
        ListNode* temp = head;
        for(int i=1;i<random_number;i++) temp = temp->next;
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */