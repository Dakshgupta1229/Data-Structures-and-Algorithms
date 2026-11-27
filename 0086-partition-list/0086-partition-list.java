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
    public ListNode partition(ListNode head, int x) {
        ListNode less = new ListNode(1000);
        ListNode greater = new ListNode(1000);
        ListNode l = less;
        ListNode g = greater;
        while(head!=null){
            if(head.val<x){
                less.next = head;
                less = less.next;
            }
            else{
                greater.next = head;
                greater = greater.next;
            }
            head = head.next;
        }
        greater.next = null;
        less.next = g.next;
        return l.next;
    }
}