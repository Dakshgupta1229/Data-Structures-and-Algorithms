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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result = new ListNode(100);
        ListNode r = result;
        int carry = 0;
        while(l1!=null && l2!=null){
            int sum = l1.val + l2.val + carry;
            int digit = sum%10;
            sum = sum/10;
            if(sum!=0) carry = sum;
            else carry = 0;
            ListNode t = new ListNode(digit);
            result.next = t;
            result = result.next;
            l1 = l1.next;
            l2 = l2.next;
        }
        while(l1!=null){
            int sum = l1.val + carry;
            int digit = sum%10;
            sum = sum/10;
            if(sum!=0) carry = sum;
            else carry = 0;
            ListNode t = new ListNode(digit);
            result.next = t;
            result = result.next;
            l1 = l1.next;
        }
        while(l2!=null){
            int sum = l2.val + carry;
            int digit = sum%10;
            sum = sum/10;
            if(sum!=0) carry = sum;
            else carry = 0;
            ListNode t = new ListNode(digit);
            result.next = t;
            result = result.next;
            l2 = l2.next;
        }
        if(carry!=0){
            ListNode t = new ListNode(carry);
            result.next = t;
        }
        return r.next;
    }
}