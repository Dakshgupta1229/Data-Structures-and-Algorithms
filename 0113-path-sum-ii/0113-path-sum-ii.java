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

    void traverse(TreeNode root,int sum,int targetSum,List<Integer> list1,List<List<Integer>> list){
        if(root==null) return;
        if(root.left==null && root.right==null){
            sum = sum + root.val;
            list1.add(root.val);
            if(sum==targetSum) list.add(new ArrayList<>(list1));
            list1.remove(list1.size()-1);
            return;
        }
        list1.add(root.val);
        traverse(root.left,sum+root.val,targetSum,list1,list);
        traverse(root.right,sum+root.val,targetSum,list1,list);
        list1.remove(list1.size()-1);
    }

    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        List<List<Integer>> list = new ArrayList<>();
        List<Integer> list1 = new ArrayList<>();
        traverse(root,0,targetSum,list1,list);
        return list;
    }
}