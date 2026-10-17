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

    void traverse(TreeNode root,int[] arr){
        if(root==null) return;
        if(root.left!=null){
            if(root.left.left==null && root.left.right==null){
                arr[0] = arr[0] + root.left.val;
            }
        }
        traverse(root.left,arr);
        traverse(root.right,arr);
    }

    public int sumOfLeftLeaves(TreeNode root) {
        int[] arr = {0};
        traverse(root,arr);
        return arr[0];
    }
}