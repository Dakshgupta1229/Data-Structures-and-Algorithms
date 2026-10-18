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

    void traverse2(TreeNode root,int target,long sum,int[] arr){
        if(root==null) return;
        sum = sum + root.val;
        if(sum==target) arr[0] = arr[0] + 1;
        traverse2(root.left,target,sum,arr);
        traverse2(root.right,target,sum,arr);
    }

    void traverse(TreeNode root,int targetSum,int[] arr){
        if(root==null) return;
        traverse2(root,targetSum,0,arr);
        traverse(root.left,targetSum,arr);
        traverse(root.right,targetSum,arr);
    }

    public int pathSum(TreeNode root, int targetSum) {
        int[] arr = {0};
        traverse(root,targetSum,arr);
        return arr[0];
    }
}