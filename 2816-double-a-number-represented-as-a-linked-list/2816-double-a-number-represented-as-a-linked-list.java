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
    public ListNode doubleIt(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;
        ListNode temp = null;
        while(curr!=null){
            temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
        }
        ListNode result = new ListNode(100);
        ListNode r = result;
        int carry = 0;
        while(prev!=null){
            int sum = 2 * prev.val + carry;
            int digit = sum;
            if(sum>=10){
                digit = sum%10;
                carry = 1;
            }
            else carry = 0;
            ListNode tt = new ListNode(digit);
            result.next = tt;
            result = result.next;
            prev = prev.next;
        }
        if(carry!=0){
            ListNode tt = new ListNode(carry);
            result.next = tt;
            result = result.next;
        }
        prev = null;
        curr = r.next;
        temp = null;
        while(curr!=null){
            temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
}