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

    public ListNode rotateRight(ListNode head, int k) {
        int n = size(head);
        if(n==0) return null;
        k = k%n;
        if(k==0) return head;
        ListNode temp = head;
        for(int i=0;i<n-k-1;i++) temp = temp.next;
        ListNode temp2 = temp.next;
        temp.next = null;
        ListNode temp3 = temp2;
        while(temp3.next!=null) temp3 = temp3.next;
        temp3.next = head;
        return temp2;

    }
}