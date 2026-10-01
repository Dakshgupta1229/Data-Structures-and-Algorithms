/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {

    void traverse(TreeNode root,int count,int[] arr){
        if(root==null) return;
        if(root.left==null && root.right==null){
            count++;
            if(arr[0]>count) arr[0] = count;
            return;
        }
        traverse(root.left,count+1,arr);
        traverse(root.right,count+1,arr);
    }

    public int minDepth(TreeNode root) {
        int[] arr = {Integer.MAX_VALUE};
        traverse(root,0,arr);
        if(arr[0]==Integer.MAX_VALUE) return 0;
        return arr[0];
    }
}