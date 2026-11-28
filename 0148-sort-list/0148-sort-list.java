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

    ListNode merge(ListNode list1,ListNode list2){
        ListNode list = new ListNode(10);
        ListNode l = list;
        while(list1!=null && list2!=null){
            if(list1.val<=list2.val){
                list.next = list1;
                list1 = list1.next;
            }
            else{
                list.next = list2;
                list2 = list2.next;
            }
            list = list.next;
        }
        while(list1!=null){
            list.next = list1;
            list = list.next;
            list1 = list1.next;
        }
        while(list2!=null){
            list.next = list2;
            list = list.next;
            list2 = list2.next;
        }
        return l.next;
    }

    public ListNode sortList(ListNode head) {
        if(head==null || head.next==null) return head;
        ListNode slow = head;
        ListNode fast = head;
        while(fast.next!=null && fast.next.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode first = head;
        ListNode second = slow.next;
        slow.next = null;
        ListNode list1 = sortList(first);
        ListNode list2 = sortList(second);
        ListNode result = merge(list1,list2);
        return result;
    }
}