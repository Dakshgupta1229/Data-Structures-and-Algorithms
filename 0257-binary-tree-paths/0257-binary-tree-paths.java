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

    public void traverse(TreeNode root,String str,List<String> list){
        if(root==null) return;
        if(root.left==null && root.right==null){
            str = str + String.valueOf(root.val);
            list.add(str);
            return;
        }
        traverse(root.left,str+String.valueOf(root.val)+"->",list);
        traverse(root.right,str+String.valueOf(root.val)+"->",list);
    }

    public List<String> binaryTreePaths(TreeNode root) {
        List<String> list = new ArrayList<>();
        traverse(root,"",list);
        return list;
    }
}