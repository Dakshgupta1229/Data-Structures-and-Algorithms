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
        vector<int> v;
        int first = head->val;
        head = head->next;
        int count = 2;
        while(head->next!=NULL){
            int second = head->val;
            int third = head->next->val;
            if(second<first && second<third) v.push_back(count);
            if(second>first && second>third) v.push_back(count);
            count++;
            first = second;
            head = head->next;
        }
        if(v.size()==0 || v.size()==1) return {-1,-1};
        int max_distance = v[v.size()-1] - v[0];
        int min_distance = INT_MAX;
        for(int i=1;i<v.size();i++){
            if(min_distance>(v[i] - v[i-1])){
                min_distance = v[i] - v[i-1];
            }
        }
        return {min_distance,max_distance};
    }
};