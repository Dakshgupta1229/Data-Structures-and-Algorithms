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

    void traverse(TreeNode root,int[] max_length){
        if(root==null) return;
        int sum = level(root.left) + level(root.right);
        if(max_length[0]<sum) max_length[0] = sum;
        traverse(root.left,max_length);
        traverse(root.right,max_length);
    }

    public int diameterOfBinaryTree(TreeNode root) {
        int[] max_length = {0};
        traverse(root,max_length);
        return max_length[0];
    }
}