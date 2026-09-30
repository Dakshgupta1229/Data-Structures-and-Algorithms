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

    public ListNode merge(ListNode list1,ListNode list2){
        ListNode temp = new ListNode(100);
        ListNode t= temp;
        while(list1!=null && list2!=null){
            if(list1.val < list2.val){
                temp.next = list1;
                temp = temp.next;
                list1 = list1.next;
            }
            else{
                temp.next = list2;
                temp = temp.next;
                list2 = list2.next;
            }
        }
        if(list1!=null) temp.next = list1;
        if(list2!=null) temp.next = list2;
        return t.next;
    }

    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length==0) return null;
        ArrayList<ListNode> arr = new ArrayList<>();
        for(int i=0;i<lists.length;i++) arr.add(lists[i]);
        while(arr.size()>1){
            ListNode list1 = arr.get(arr.size()- 1);
            ListNode list2 = arr.get(arr.size() - 2);
            arr.remove(arr.size() - 1);
            arr.remove(arr.size() - 1);
            ListNode result = merge(list1,list2);
            arr.add(result);
        }
        return arr.get(0);
    }
}