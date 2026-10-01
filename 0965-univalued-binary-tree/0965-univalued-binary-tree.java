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

    public void traverse(TreeNode root,int value,int[] arr){
        if(root==null) return;
        if(root.val!=value){
            arr[0] = -1;
            return;
        }
        if(arr[0]==-1) return;
        traverse(root.left,value,arr);
        traverse(root.right,value,arr);
    }

    public boolean isUnivalTree(TreeNode root) {
        int value = root.val;
        int[] arr = {0};
        traverse(root,value,arr);
        if(arr[0]==0) return true;
        return false;
    }
}