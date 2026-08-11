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
        ListNode* temp = head;
        int count = 1;
        int val1 = temp->val;
        temp = temp->next;
        while(temp->next!=NULL){
            int val2 = temp->val;
            int val3 = temp->next->val;
            if(val2>val1 && val2>val3) v.push_back(count+1);
            if(val2<val1 && val2<val3) v.push_back(count+1);
            val1 = temp->val;
            temp = temp->next;
            count++;
        }
        if(v.size()==0 || v.size()==1) return {-1,-1};
        sort(v.begin(),v.end());
        int max_dist = v[v.size()-1] - v[0];
        int min_dist = INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            if(min_dist>(v[i+1] - v[i])) min_dist = v[i+1] - v[i];
        }
        return {min_dist,max_dist};

    }
};