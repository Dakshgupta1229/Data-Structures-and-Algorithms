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

    void traverse(TreeNode root,String str,int[] arr){
        if(root==null) return;
        if(root.left==null && root.right==null){
            str = str + Integer.toString(root.val);
            arr[0] = arr[0] + Integer.parseInt(str);
            return;
        }
        traverse(root.left,str +Integer.toString(root.val),arr);
        traverse(root.right,str + Integer.toString(root.val),arr);
    }

    public int sumNumbers(TreeNode root) {
        int[] arr = {0};
        traverse(root,"",arr);
        return arr[0];
    }
}