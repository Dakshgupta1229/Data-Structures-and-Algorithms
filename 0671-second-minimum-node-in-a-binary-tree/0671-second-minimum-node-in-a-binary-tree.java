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

    void traverse(TreeNode root,List<Integer> list){
        if(root==null) return;
        list.add(root.val);
        traverse(root.left,list);
        traverse(root.right,list);
    }

    public int findSecondMinimumValue(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        traverse(root,list);
        int min_value = list.get(0);
        long s_value = Long.MAX_VALUE;
        for(int i=1;i<list.size();i++){
            if(min_value>list.get(i)){
                s_value = min_value;
                min_value = list.get(i);
            }
            if(s_value>list.get(i) && list.get(i)!=min_value){
                s_value = list.get(i);
            }
        }
        return (int)s_value;
    }
}