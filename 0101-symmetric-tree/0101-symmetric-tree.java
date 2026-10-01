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

    public void traverse(TreeNode root1,TreeNode root2,int[] arr){
        if(root1==null && root2==null) return;
        if(root1==null || root2==null){
            arr[0] = 1;
            return;
        }
        if(root1.val!=root2.val){
            arr[0] = 1;
            return;
        }
        traverse(root1.left,root2.right,arr);
        traverse(root1.right,root2.left,arr);
    }

    public boolean isSymmetric(TreeNode root) {
        int[] arr = {0};
        traverse(root.left,root.right,arr);
        if(arr[0]==0) return true;
        return false;
    }
}