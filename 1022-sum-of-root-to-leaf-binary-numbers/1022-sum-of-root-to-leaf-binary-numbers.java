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

    void traverse(TreeNode root,List<Integer> list,int []arr){
        if(root==null) return;
        if(root.left==null && root.right==null){
            list.add(root.val);
            int idx = 0;
            int sum = 0;
            for(int i=list.size()-1;i>=0;i--){
                sum = sum + ((int)Math.pow(2,idx) * list.get(i));
                idx++;
            }
            arr[0] = arr[0] + sum;
            list.remove(list.size()-1);
            return;
        }
        list.add(root.val);
        traverse(root.left,list,arr);
        traverse(root.right,list,arr);
        list.remove(list.size()-1);
    }

    public int sumRootToLeaf(TreeNode root) {
        int[] arr = {0};
        List<Integer> list = new ArrayList<>();
        traverse(root,list,arr);
        return arr[0];
    }
}