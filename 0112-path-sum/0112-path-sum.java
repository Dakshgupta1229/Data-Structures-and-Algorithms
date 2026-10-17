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

    void traverse(TreeNode root,int target,int sum,int[] arr){
        if(root==null) return;
        if(root.left==null && root.right==null){
            sum = sum + root.val;
            if(sum==target){
                arr[0] = 1;
                return;
            }
        }
        if(arr[0]==1) return;
        traverse(root.left,target,sum+root.val,arr);
        traverse(root.right,target,sum+root.val,arr);
    }

    public boolean hasPathSum(TreeNode root, int targetSum) {
        int[] arr = {0};
        traverse(root,targetSum,0,arr);
        if(arr[0]==1) return true;
        return false;
    }
}