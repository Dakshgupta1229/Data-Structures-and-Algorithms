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
        if(head.next.next==null) return new int[]{-1,-1};
        int val1 = head.val;
        head = head.next;
        ArrayList<Integer> arr = new ArrayList<>();
        int count = 2;
        while(head.next!=null){
            int val2 = head.val;
            int val3 = head.next.val;
            if(val2>val1 && val2>val3){
                arr.add(count);
            }
            if(val2<val1 && val2<val3){
                arr.add(count);
            }
            val1 = val2;
            count++;
            head = head.next;
        }
        if(arr.size()<=1) return new int[]{-1,-1};
        int min_distance = Integer.MAX_VALUE;
        for(int i=1;i<arr.size();i++){
            if(min_distance>(arr.get(i) - arr.get(i-1))) min_distance = arr.get(i) - arr.get(i-1);
        }
        return new int[]{min_distance,arr.get(arr.size()-1) - arr.get(0)};
    }
}