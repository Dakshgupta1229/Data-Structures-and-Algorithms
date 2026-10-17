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

    void traverse(TreeNode root,List<String> list,String str){
        if(root==null) return;
        if(root.left==null && root.right==null){
            str = str + Integer.toString(root.val);
            list.add(str);
            return;
        }
        str = str + Integer.toString(root.val);
        str = str + "->";
        traverse(root.left,list,str);
        traverse(root.right,list,str);
    }

    public List<String> binaryTreePaths(TreeNode root) {
        List<String> list = new ArrayList<>();
        traverse(root,list,"");
        return list;
    }
}