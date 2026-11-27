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
        if(n==0 || k==0) return head;
        k = k%n;
        if(n==k || k==0) return head;
        ListNode temp = head;
        ListNode first = head;
        for(int i=0;i<n-k-1;i++){
            temp = temp.next;
        }
        ListNode second = temp.next;
        temp.next = null;
        ListNode third = second;
        while(third.next!=null){
            third = third.next;
        }
        third.next = head;
        return second;
    }
}