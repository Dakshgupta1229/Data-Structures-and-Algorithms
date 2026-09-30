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
        ListNode greater = new ListNode(100);
        ListNode g = greater;
        ListNode lesser = new ListNode(100);
        ListNode l = lesser;
        while(head!=null){
            if(head.val<x){
                lesser.next = head;
                lesser = lesser.next;
                head = head.next;
            }
            else{
                greater.next = head;
                greater = greater.next;
                head = head.next;
            }
        }
        greater.next = null;
        lesser.next = g.next;
        return l.next;
    }
}