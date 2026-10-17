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

    int level(TreeNode root){
        if(root==null) return 0;
        return 1 + Math.max(level(root.left),level(root.right));
    }

    void traverse(TreeNode root,int[] arr){
        if(root==null) return;
        int left_tree = level(root.left);
        int right_tree = level(root.right);
        if(Math.abs(left_tree-right_tree)>1){
            arr[0] = 1;
            return;
        }
        if(arr[0]==1) return;
        traverse(root.left,arr);
        traverse(root.right,arr);
    }

    public boolean isBalanced(TreeNode root) {
        int[] arr = {0};
        traverse(root,arr);
        if(arr[0]==0) return true;
        return false;
    }
}