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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next->next==NULL) return {-1,-1};
        int val1 = head->val;
        head = head->next;
        int count = 2;
        vector<int> v;
        while(head->next!=NULL){
            int val2 = head->val;
            int val3 = head->next->val;
            if(val2>val1 && val2>val3){
                v.push_back(count);
            }
            if(val2<val1 && val2<val3){
                v.push_back(count);
            }
            val1 = val2;
            head = head->next;
            count++;
        }
        int min_distance = INT_MAX;
        for(int i=1;i<v.size();i++){
            if(min_distance>(v[i] - v[i-1])) min_distance = v[i] - v[i-1];
        }
        if(v.size()<=1) return {-1,-1};
        return {min_distance,v[v.size()-1] - v[0]};
    }
};