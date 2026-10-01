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
    ListNode head;
    int n;
    public Solution(ListNode head) {
        this.head = head;
        this.n = size(head);
    }

    public int size(ListNode head){
        int count = 0;
        while(head!=null){
            count++;
            head = head.next;
        }
        return count;
    }
    
    public int getRandom() {
        int low = 1;
        int high = n;
        Random random = new Random();
        int num = random.nextInt(low + high - 1) + low;
        int count = 1;
        ListNode temp = head;
        while(temp!=null){
            if(count==num) return temp.val;
            temp = temp.next;
            count++;
        }
        return -1;
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */