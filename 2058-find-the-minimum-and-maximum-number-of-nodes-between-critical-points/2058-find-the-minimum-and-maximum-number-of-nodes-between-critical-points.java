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
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        ArrayList<Integer> list = new ArrayList<>();
        int val1 = head.val;
        head = head.next;
        int count = 2;
        while(head.next!=null){
            int val2 = head.val;
            int val3 = head.next.val;
            if(val2>val1 && val2>val3){
                list.add(count);
            }
            if(val2<val1 && val2<val3) list.add(count);
            count++;
            val1 = val2;
            head = head.next;
        }
        int min_distance = Integer.MAX_VALUE;
        if(list.size()<=1) return new int[]{-1,-1};
        for(int i=1;i<list.size();i++){
            if(min_distance>list.get(i)-list.get(i-1)){
                min_distance = list.get(i) - list.get(i-1);
            }
        }
        return new int[]{min_distance,list.get(list.size()-1) - list.get(0)};
    }
}