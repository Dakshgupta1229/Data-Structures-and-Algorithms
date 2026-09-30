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
    public ListNode oddEvenList(ListNode head) {
        ListNode odd = new ListNode(100);
        ListNode o = odd;
        ListNode even = new ListNode(100);
        ListNode e = even;
        int count = 1;
        while(head!=null){
            if(count%2!=0){
                odd.next = head;
                odd = odd.next;
                head = head.next;
            }
            else{
                even.next = head;
                even = even.next;
                head = head.next;
            }
            count++;
        }
        even.next = null;
        odd.next = e.next;
        return o.next;
    }
}