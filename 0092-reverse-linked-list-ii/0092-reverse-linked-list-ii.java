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
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if(left==right) return head;
        ListNode first = null;
        ListNode second = null;
        ListNode third = null;
        ListNode fourth = null;
        int count = 1;
        ListNode temp = head;
        while(temp!=null){
            if(count==left-1) first = temp;
            if(count==left) second = temp;
            if(count==right) third = temp;
            if(count==(right+1)) fourth = temp;
            count++;
            temp = temp.next;
        }
        if(left!=1) first.next = null;
         third.next = null;
        ListNode prev = null;
        ListNode curr = second;
        ListNode temp2 = null;
        while(curr!=null){
            temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
        }
        if(left==1){
            second.next = fourth;
            return third;
        }
        first.next = prev;
        second.next = fourth;
        return head;
    }
}