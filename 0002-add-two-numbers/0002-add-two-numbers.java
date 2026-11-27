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
        ListNode temp = new ListNode(1000);
        ListNode t = temp;
        int carry = 0;
        while(l1!=null && l2!=null){
            int sum = l1.val + l2.val + carry;
            int digit = sum;
            if(sum>=10){
                digit = digit%10;
                carry = 1;
            }
            else carry = 0;
            ListNode tt = new ListNode(digit);
            temp.next = tt;
            temp = temp.next;
            l1 = l1.next;
            l2 = l2.next;
        }
        while(l1!=null){
            int sum = l1.val + carry;
            int digit = sum;
            if(sum>=10){
                digit = digit%10;
                carry = 1;
            }
            else carry = 0;
            ListNode tt = new ListNode(digit);
            temp.next = tt;
            temp = temp.next;
            l1 = l1.next;
        }
        while(l2!=null){
            int sum = l2.val + carry;
            int digit = sum;
            if(sum>=10){
                digit = digit%10;
                carry = 1;
            }
            else carry = 0;
            ListNode tt = new ListNode(digit);
            temp.next = tt;
            temp = temp.next;
            l2 = l2.next;
        }
        if(carry!=0){
            ListNode tt = new ListNode(carry);
            temp.next = tt;
            temp = temp.next;
        }
        temp.next = null;
        return t.next;
    }
}