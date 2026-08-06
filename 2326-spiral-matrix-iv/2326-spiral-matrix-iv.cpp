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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> v(m,vector<int>(n,-1));
        int min_row = 0;
        int max_row = m-1;
        int min_column = 0;
        int max_column = n-1;
        ListNode* temp = head;
        while(min_row<=max_row && min_column<=max_column){
            for(int i=min_column;i<=max_column;i++){
                if(temp==NULL) break;
                v[min_row][i] = temp->val;
                temp = temp->next;
            }
            min_row++;
            if(min_row>max_row || min_column>max_column) break;
            for(int i=min_row;i<=max_row;i++){
                if(temp==NULL) break;
                v[i][max_column] = temp->val;
                temp = temp->next;
            }
            max_column--;
            if(min_row>max_row || min_column>max_column) break;
            for(int i=max_column;i>=min_column;i--){
                if(temp==NULL) break;
                v[max_row][i] = temp->val;
                temp = temp->next;
            }
            max_row--;
            if(min_row>max_row || min_column>max_column) break;
            for(int i=max_row;i>=min_row;i--){
                if(temp==NULL) break;
                v[i][min_column] = temp->val;
                temp = temp->next;
            }
            min_column++;
        }
        return v;
    }
};