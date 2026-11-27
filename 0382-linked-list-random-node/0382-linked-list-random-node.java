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
    List<Integer> list = new ArrayList<>();
    public Solution(ListNode head) {
        ListNode temp = head;
        while(temp!=null){
            list.add(temp.val);
            temp = temp.next;
        }
    }
    
    public int getRandom() {
        int min = 0;
        int max = list.size()-1;
        int number = (int)(Math.random() * (max-min+1)) + min;
        return list.get(number);
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */