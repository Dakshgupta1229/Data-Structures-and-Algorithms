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
        while(min_row<=max_row && min_column<=max_column){
            // right
            for(int i=min_column;i<=max_column;i++){
                if(head==NULL) break;
                v[min_row][i] = head->val;
                head = head->next;
            }
            min_row++;
            //down
            for(int i=min_row;i<=max_row;i++){
                if(head==NULL) break;
                v[i][max_column] = head->val;
                head = head->next;
            }
            max_column--;
            //left
            for(int i=max_column;i>=min_column;i--){
                if(head==NULL) break;
                v[max_row][i] = head->val;
                head = head->next;
            }
            max_row--;
            //up
            for(int i=max_row;i>=min_row;i--){
                if(head==NULL) break;
                v[i][min_column] = head->val;
                head = head->next;
            }
            min_column++;
        }
        return v;
    }
};