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

    int size(ListNode head){
        int count = 0;
        while(head!=null){
            count++;
            head = head.next;
        }
        return count;
    }

    public ListNode swapNodes(ListNode head, int k) {
        int n = size(head);
        ListNode temp1 = null;
        ListNode temp2 = null;
        int count = 1;
        ListNode temp = head;
        while(temp!=null){
            if(count==k) temp1 = temp;
            if(count==(n-k+1)) temp2 = temp;
            temp = temp.next;
            count++;
        }
        int val = temp1.val;
        temp1.val = temp2.val;
        temp2.val = val;
        return head;
    }
}