/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[][] spiralMatrix(int m, int n, ListNode head) {
        int[][] matrix = new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = -1;
            }
        }
        int min_row = 0;
        int max_row = m-1;
        int min_column = 0;
        int max_column = n-1;
        while(min_row<=max_row && min_column<=max_column){
            for(int i=min_column;i<=max_column;i++){
                if(head==null) break;
                matrix[min_row][i] = head.val;
                head = head.next;
            }
            min_row++;
            if(min_row>max_row || min_column>max_column) break;
            for(int i=min_row;i<=max_row;i++){
                if(head==null) break;
                matrix[i][max_column] = head.val;
                head = head.next;
            }
            max_column--;
            if(min_row>max_row || min_column>max_column) break;
            for(int i=max_column;i>=min_column;i--){
                if(head==null) break;
                matrix[max_row][i] = head.val;
                head = head.next;
            }
            max_row--;
            if(min_row>max_row || min_column>max_column) break;
            for(int i=max_row;i>=min_row;i--){
                if(head==null) break;
                matrix[i][min_column] = head.val;
                head = head.next;
            }
            min_column++;
        }
        return matrix;
    }
}