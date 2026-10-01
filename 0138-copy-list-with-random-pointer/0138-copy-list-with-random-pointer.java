/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        Node temp = new Node(10);
        Node t = temp;
        Node temp2 = head;
        while(temp2!=null){
            Node tt = new Node(temp2.val);
            temp.next = tt;
            temp = temp.next;
            temp2 = temp2.next;
        }
        t = t.next;
        Node result = new Node(10);
        Node r = result;
        while(head!=null && t!=null){
            result.next = head;
            result = result.next;
            head = head.next;
            result.next = t;
            result = result.next;
            t = t.next;
        }
        r = r.next;
        Node temp3 = r;
        while(temp3!=null){
            if(temp3.random==null) temp3.next.random = null;
            else temp3.next.random = temp3.random.next;
            temp3 = temp3.next.next;
        }
        Node first = new Node(10);
        Node f = first;
        Node second = new Node(10);
        Node s = second;
        while(r!=null){
            first.next = r;
            first = first.next;
            r = r.next;
            second.next = r;
            second = second.next;
            r = r.next;
        }
        first.next = null;
        second.next = null;
        head = f.next;
        return s.next;

    }
}